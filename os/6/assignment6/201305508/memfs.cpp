#define FUSE_USE_VERSION 26
#define _GNU_SOURCE

#include <sys/types.h>
#include<sys/stat.h>
#include <sys/mman.h>
#include<iostream>

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
#include<map>
#include<string>
#include<libgen.h>
#include<unistd.h>

using namespace std;
struct memFS_super {
	uint8_t		res1[3];
	char		oemname[8];
	uint16_t	bytes_per_sector;
	uint8_t		sectors_per_cluster;
	uint16_t	reserved_sectors;
	uint8_t		fat_count;
	uint16_t	root_max_entries;
	uint16_t	total_sectors_small;
	uint8_t		media_info;
	uint16_t	sectors_per_fat_small;
	uint16_t	sectors_per_track;
	uint16_t	head_count;
	uint32_t	fs_offset;
	uint32_t	total_sectors;
	uint32_t	sectors_per_fat;
	uint16_t	fat_flags;
	uint16_t	version;
	uint32_t	root_cluster;
	uint16_t	fsinfo_sector;
	uint16_t	backup_sector;
	uint8_t		res2[12];
	uint8_t		drive_number;
	uint8_t		res3;
	uint8_t		ext_sig;
	uint32_t	serial;
	char		label[11];
	char		type[8];
	char		res4[420];
	uint16_t	sig;
} __attribute__ ((__packed__));

struct memFS_direntry {
	/*union {
		struct {
			char		name[8];
			char		ext[3];
		};
		char			nameext[11];
	};*/
	string 		name;
	string		type;
	uint8_t		attr;
	uint8_t		res;
	time_t		ctime;
	mode_t		st_mode;
	uid_t		st_uid;
	gid_t		st_gid;
	uint16_t	ctime_date;
	time_t		atime;
	uint16_t	cluster_hi;
	time_t		mtime;
	uint16_t	mtime_date;
	uint16_t	cluster_lo;
	uint32_t	size;
	string		content;
	map<string,struct memFS_direntry*> files;
} ;

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
} __attribute__ ((__packed__));

#define memFS_LFN_SEQ_START	0x40
#define memFS_LFN_SEQ_DELETED	0x80
#define memFS_LFN_SEQ_MASK	0x3f

struct memFS {
	const char	*dev;
	int		fs;
	struct memFS_direntry *diren;
	/* XXX add your code here */
};

struct memFS_search_data {
	const char	*name;
	int		found;
	struct stat	*st;
};

struct memFS memFS_info, *f = &memFS_info;
iconv_t iconv_utf16;

uid_t mount_uid;
gid_t mount_gid;
time_t mount_time;
size_t pagesize;


static void
memFS_init(const char *dev)
{
	iconv_utf16 = iconv_open("utf-8", "utf-16");
	mount_uid = getuid();
	mount_gid = getgid();
	mount_time = time(NULL);
	pagesize=1024; //1K
	cout<<"init  "<<dev<<endl;

	f->fs = open(dev, O_RDONLY);
	if (f->fs < 0)
		err(1, "open(%s)", dev);
	struct memFS_direntry *diren=new memFS_direntry();

	diren->ctime=time(NULL);
	diren->atime=time(NULL);
	diren->mtime=time(NULL);
	diren->st_uid=mount_uid;
	diren->st_gid=mount_gid;
	diren->st_mode=0755|S_IFDIR;
	f->diren=diren;
}

struct memFS_direntry* getEntry(const char* path, bool dir){
	char *dirc, *basec, *dname, *bname;
	cout<<"getEntry  "<<path<<endl;
	dirc = strdup(path);
        basec = strdup(path);
        dname = dirname(dirc);
        bname = basename(basec);
	string sfile;
        // printf("dirname=%s, basename=%s\n", dname, bname);
	map<string,struct memFS_direntry*> files=(f->diren)->files;
	struct memFS_direntry *parent=f->diren;

	if( strcmp("/",bname) == 0 && strcmp("/",dname) == 0 )
		return parent;
	
	char *cur=strtok(dname,"/");
	while( cur != NULL)
	{
		//cout<<cur<<endl;
		sfile=cur;
		if(files[sfile] == NULL)
			return NULL;
		parent=files[sfile];
		files=files[sfile]->files;
		cur=strtok(NULL,"/");
	}
	//cout<<bname<<endl;
	if(dir)
		return parent;
	sfile=bname;
	return files[sfile];
}

/* XXX add your code here */

/*static int
memFS_readdir2(const char *path,void *buf, fuse_fill_dir_t filler,off_t offset,
		struct fuse_file_info *fi)
{
	struct stat st;
	void *buf = NULL;
	struct memFS_direntry *e;
	char *name;

	memset(&st, 0, sizeof(st));
	st.st_uid = mount_uid;
	st.st_gid = mount_gid;
	st.st_nlink = 1;

}*/

static int
memFS_search_entry(void *data, const char *name, const struct stat *st, off_t offs)
{
/*	struct memFS_search_data *sd = data;

	if (strcmp(sd->name, name) != 0)
		return (0);

	sd->found = 1;
	*sd->st = *st;*/

	return (1);
}
	
static int
memFS_resolve(const char *path, struct stat *st)
{
	struct memFS_search_data sd;

	/* XXX add your code here */
}

static int
memFS_fuse_getattr(const char *path, struct stat *st)
{
	cout<<"getatt "<<path<<endl;
	struct memFS_direntry *diren=getEntry(path,false);
	if(diren == NULL)
		return -ENOENT;
//	st=new stat();
	st=(struct stat*)malloc(sizeof(struct stat));
	st->st_mode=diren->st_mode;
	st->st_uid=diren->st_uid;
	st->st_gid=diren->st_gid;
	st->st_size=100;
	st->st_atime=diren->atime;
	st->st_ctime=diren->ctime;
	st->st_mtime=diren->mtime;
	return 0;
}

static int
memFS_fuse_readdir(const char *path, void *data,
		  fuse_fill_dir_t filler, off_t offs, struct fuse_file_info *fi)
{
	(void) offs;
	(void) fi;
	struct memFS_direntry *diren=getEntry(path,false);
	map<string,struct memFS_direntry*> files;
	if( !diren){
		return -ENOENT;
	}
	files = diren->files;
	filler(data,".",NULL,0);
	filler(data,"..",NULL,0);
	for(map<string,struct memFS_direntry *>::iterator it = files.begin();
			it != files.end(); it++){
		filler(data,it->first.c_str(),NULL,0);
	}
	return 0;
}

static int
memFS_fuse_read(const char *path, char *buf, size_t size, off_t offs,
	       struct fuse_file_info *fi)
{
	struct memFS_direntry* diren=getEntry(path,false);
	if( diren == NULL)
		return -ENOENT;
	unsigned len=diren->content.length();
	if(offs < diren->content.length()){

		if( offs + size > len)
			size=len-offs;
		memcpy(buf,diren->content.c_str()+offs,size);
	}
	else 
		return 0;

	return size;
}
static int memFS_fuse_create(const char *path,mode_t mode,struct fuse_file_info *fi)
{
	struct memFS_direntry *diren=getEntry(path,true);
	if(diren == NULL)
		return -ENOENT;
	char *bname;
	bname=basename(strdup(path));
	struct memFS_direntry *newEntry= new memFS_direntry();
	string name=bname;
	newEntry->name=name;
	newEntry->st_mode=mode|S_IFREG;
	newEntry->st_uid=getuid();
	newEntry->st_gid=getgid();
	newEntry->ctime=time(NULL);
	newEntry->atime=time(NULL);
	newEntry->mtime=time(NULL);
	newEntry->size=0;
	diren->files[name]=newEntry;
	return 0;
}
static int memFS_fuse_open(const char *path, struct fuse_file_info *fi){
	struct memFS_direntry *diren=getEntry(path,false);
	if( diren == NULL)
		return -ENOENT;
	return 0;
}

static int memFS_fuse_mkdir(const char *path,mode_t mode)
{
	struct memFS_direntry *diren=getEntry(path,true);
	if(diren == NULL)
		return -ENOENT;
	char *bname;
	bname=basename(strdup(path));
	struct memFS_direntry *newEntry= new memFS_direntry();
	string name=bname;
	newEntry->name=name;
	newEntry->st_mode= 0755 | S_IFDIR;// mode| S_IFDIR;
	newEntry->st_uid=getuid();
	newEntry->st_gid=getgid();
	newEntry->ctime=time(NULL);
	newEntry->atime=time(NULL);
	newEntry->mtime=time(NULL);
	newEntry->size=0;
	diren->files[name]=newEntry;
	return 0;
}
static int
memFS_fuse_write(const char *path,const char *buf, size_t size, off_t offs,
	       struct fuse_file_info *fi){
	struct memFS_direntry *diren=getEntry(path,false);
	if(diren == NULL)
		return -ENOENT;
	char *lbuf;
	memcpy(lbuf,buf,size);
	string newData;
	newData=lbuf;
	string oldData=diren->content;
	diren->ctime=time(NULL);
	diren->mtime=time(NULL);
	
	//at starting
	if( offs == 0)
	{
		diren->content=newData+oldData;
	}else if(offs == oldData.length()){ // at end
		diren->content=oldData+newData;
	}else{ 					//in middle
		string firstPart,secondPart;
		char *first,*second;
		memcpy(first,oldData.c_str(),offs-1);
		memcpy(second,oldData.c_str()+offs,oldData.length()-offs);
		firstPart=first;
		secondPart=second;
		diren->content=firstPart+newData+secondPart;
	}
}

int memFS_fuse_utime(const char *path,struct utimbuf *ubuf){
	return 0;
}

static int
memFS_opt_args(void *data, const char *arg, int key, struct fuse_args *oargs)
{
	if (key == FUSE_OPT_KEY_NONOPT && !f->dev) {
		f->dev = strdup(arg);
		return (0);
	}
	return (1);
}

struct memFS_fuse_operations:fuse_operations{
	memFS_fuse_operations(){
	//	getattr = memFS_fuse_getattr;
		readdir = memFS_fuse_readdir;
		read = memFS_fuse_read;
		create = memFS_fuse_create;
		write = memFS_fuse_write;
		utime = memFS_fuse_utime;
		open =memFS_fuse_open;
		mkdir = memFS_fuse_mkdir;
	}
};
static struct memFS_fuse_operations memFS_ops;

int
main(int argc, char **argv)
{
	struct fuse_args args = FUSE_ARGS_INIT(argc, argv);

	fuse_opt_parse(&args, NULL, NULL, memFS_opt_args);

	if (!f->dev)
		errx(1, "missing file system parameter");

	memFS_init(f->dev);
	return (fuse_main(args.argc, args.argv, &memFS_ops, NULL));
}
