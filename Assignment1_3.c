#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc ,char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("INSUFFICIENT ARGUMENT....\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("%d\n",sobj.st_atime);
    printf("%d\n",sobj.st_blksize);
    printf("%d\n",sobj.st_ctime);
    printf("%d\n",sobj.st_dev);
    printf("%d\n",sobj.st_gid);
    printf("%d\n",sobj.st_ino);
    printf("%d\n",sobj.st_mode);
    printf("%d\n",sobj.st_mtime);
    printf("%d\n",sobj.st_nlink);
    printf("%d\n",sobj.st_rdev);
    printf("%d\n",sobj.st_size);
    printf("%d\n",sobj.st_uid);
    printf("%d\n",sobj.__glibc_reserved);

    return 0;   
}