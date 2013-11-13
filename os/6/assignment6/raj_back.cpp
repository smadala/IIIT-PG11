#define FUSE_USE_VERSION 26
//#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/mman.h>
#include<map>
#include<iostream>
#include<dirent.h>
#include <endian.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <fuse.h>
#include <iconv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace std;

struct memFS_direntry {
	char	content[100];
//	struct memFS_direntry *reference;
//	map<string,struct memFS_direntry *> sub_files;
	
	uint16_t	ctime_time;
	uint16_t	atime_date;
	uint16_t	mtime_time;
	uint16_t	cluster_lo;
	uint32_t	size;
};

#define memFS_ATTR_DIR	0x10
#define memFS_ATTR_LFN	0xf
#define memFS_ATTR_INVAL	(0x80|0x40|0x08)

struct memFS_direntry_lfn {
	uint8_t		seq;
	uint16_t	name1[5];
	uint8_t		attr;
	uint8_t		res1;
	uint8_t		csum;
	uint16_t	name2[6];
	uint16_t	res2;
	uint16_t	name3[2];
};

#define memFS_LFN_SEQ_START	0x40
#define memFS_LFN_SEQ_DELETED	0x80
#define memFS_LFN_SEQ_MASK	0x3f

struct memFS {
	const char	*dev;
	int		fs;
	/* XXX add your code here */
};

struct memFS_search_data {
	const char	*name;
	int		found;
	struct stat	*st;
};
map<string,struct memFS_direntry *> fs_files;

struct memFS memFS_info, *f = &memFS_info;
iconv_t iconv_utf16;

uid_t mount_uid;
gid_t mount_gid;
time_t mount_time;
size_t pagesize;


static void
memFS_init()
{
	iconv_utf16 = iconv_open("utf-8", "utf-16");
	mount_uid = getuid();
	mount_gid = getgid();
	mount_time = time(NULL);
	memFS_direntry *e1,*e2;
	e1=new memFS_direntry;
	e2=new memFS_direntry;
	strcpy(e1->content,"Last assignment!!!!\n");
	strcpy(e2->content,"1 SEM done!!!!\n");
	fs_files["/first"]=e1;
	fs_files["/second"]=e2;

}

/*static int
memFS_readdir( XXX add your code here, fuse_fill_dir_t filler, void *fillerdata)
{
	struct stat st;
	void *buf = NULL;
	struct memFS_direntry *e;
	char *name;

	memset(&st, 0, sizeof(st));
	st.st_uid = mount_uid;
	st.st_gid = mount_gid;
	st.st_nlink = 1;

	XXX add your code here 
}*/

/*static int
memFS_search_entry(void *data, const char *name, const struct stat *st, off_t offs)
{
	struct memFS_search_data *sd = (struct memFS_search_data *) data;

	if (strcmp(sd->name, name) != 0)
		return (0);

	sd->found = 1;
	*sd->st = *st;

	return (1);
}*/
/*
static int
memFS_resolve(const char *path, struct stat *st)
{
	struct memFS_search_data sd;

	XXX add your code here 
}
*/
static int
memFS_fuse_getattr(const char *path, struct stat *st)
{
	int res = 0;
	printf("hello_getattr.......%s \n",path);
	memset(st, 0, sizeof(struct stat));
	if (strcmp(path, "/") == 0) {
		st->st_mode = S_IFDIR | 0755;
		st->st_nlink = 2;
	} else if (fs_files.count(path)> 0) {
		st->st_mode = S_IFREG | 0444;
		st->st_nlink = 1;
		memFS_direntry *e;
		e=fs_files[path];
		st->st_size = strlen(e->content);
	} else
		res = -ENOENT;

	return res;

/*	int res;
		return -errno;
	res = lstat(path, stbuf);
	if (res == -1)

	return 0;*/
}

static int memFS_fuse_statfs(const char *path, struct statvfs *statv)
{	
	if(fs_files.count(path) > 0 )
	{
		statv->f_flag=ST_RDONLY;
		return 0;
	}
	return -ENOENT;
}


static int
memFS_fuse_readdir(const char *path, void *data,
		  fuse_fill_dir_t filler, off_t offs, struct fuse_file_info *fi)
{
	(void) offs;
	(void) fi;
	//printf("hello_readdir..........%s \n",path);
	if (strcmp(path, "/") != 0)
		return -ENOENT;
	filler(data, ".", NULL, 0);
	filler(data, "..", NULL, 0);
	
	for (std::map<string,struct memFS_direntry *>::iterator it=fs_files.begin(); it!=fs_files.end(); ++it)
	{	filler(data,it->first.c_str()+1, NULL, 0);
	}
	return 0;

/*	DIR *dp;
	struct dirent *de;

	(void) offs;
	(void) fi;

	dp = fdopendir(f->fs);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		struct stat st;
		memset(&st, 0, sizeof(st));
		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;
		if (filler(data, de->d_name, &st, 0))
			break;
	}

	//closedir(dp);
	return 0;*/
	/* XXX add your code here */
}

static int
memFS_fuse_read(const char *path, char *buf, size_t size, off_t offs,
	       struct fuse_file_info *fi)
{
	size_t len;
	(void) fi;
	printf("hello_read..........%s \n",path);
	if(fs_files.count(path)<= 0)
		return -ENOENT;
	struct memFS_direntry *ref;
	ref=fs_files[path];
	len = strlen(ref->content);
		
	if (offs < len) {
		if (offs + size > len)
			size = len - offs;
		memcpy(buf, ref->content + offs, size);
	} else
		size = 0;

	
	
	return size;
	/* XXX add your code here */
}
/*
static int
memFS_opt_args(void *data, const char *arg, int key, struct fuse_args *oargs)
{ 
	if (key == FUSE_OPT_KEY_NONOPT && !f->dev) {
		f->dev = strdup(arg);
		return (0);
	}
	return (1);
}
*/
struct hello_fuse_operations:fuse_operations
{
	hello_fuse_operations()
	{	
	 getattr 	= memFS_fuse_getattr;
	 readdir 	= memFS_fuse_readdir;
	 read		 = memFS_fuse_read;
	 statfs		=memFS_fuse_statfs;
	}
};

static struct hello_fuse_operations memFS_ops;

int
main(int argc, char **argv)
{
	struct fuse_args args = FUSE_ARGS_INIT(argc, argv);

/*	fuse_opt_parse(&args, NULL, NULL, memFS_opt_args);

	if (!f->dev)
		errx(1, "missing file system parameter");
 */
	memFS_init();
	return (fuse_main(args.argc, args.argv, &memFS_ops, NULL));
}
