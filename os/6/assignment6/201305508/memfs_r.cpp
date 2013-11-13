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
	time_t		ctime;
	time_t	    	atime;
	time_t		mtime;
	size_t	size;
	char	content[58];
};

struct memFS {
	const char	*dev;
	int		fs;
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
	memFS_direntry *diren1,*diren2;
	diren1=new memFS_direntry;
	diren2=new memFS_direntry;
	diren1->ctime=time(NULL);
	diren2->mtime=time(NULL);
	diren1->mtime=time(NULL);
	diren2->ctime=time(NULL);
	strcpy(diren1->content,"sample data\n");
	fs_files["/sample"]=diren1;
	strcpy(diren2->content,"thnky\n");
	fs_files["/abc"]=diren2;

}


static int
memFS_fuse_getattr(const char *path, struct stat *st)
{
	int res = 0;
	memset(st, 0, sizeof(struct stat));
	if (strcmp(path, "/") == 0) {
		st->st_mode = S_IFDIR | 0755;
		st->st_nlink = 2;
	} else if (fs_files.count(path) > 0) {
		st->st_mode = S_IFREG | 0444;
		st->st_nlink = 1;
		memFS_direntry *diren;
		diren=fs_files[path];
		st->st_ctime=diren->ctime;
		st->st_mtime=diren->mtime;
		st->st_size = strlen(diren->content);
	} else
		res = -ENOENT;
	st->st_atime=time(NULL);
	return res;
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
	if (strcmp(path, "/") != 0)
		return -ENOENT;
	filler(data, ".", NULL, 0);
	filler(data, "..", NULL, 0);
	
	for (std::map<string,struct memFS_direntry *>::iterator it=fs_files.begin(); it!=fs_files.end(); ++it)
	{	
		filler(data,it->first.c_str()+1, NULL, 0);
	}
	return 0;
}

static int
memFS_fuse_read(const char *path, char *buf, size_t size, off_t offs,
	       struct fuse_file_info *fi)
{
	size_t len;
	(void) fi;
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
		return 0;
	
	return size;
}
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
	memFS_init();
	return (fuse_main(args.argc, args.argv, &memFS_ops, NULL));
}
