#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>


int main(int argc ,char *argv[])
{

    DIR *dp = NULL;
    struct stat sobj;
    struct dirent * entry = NULL;
    char path[30];
    int fd = 0;
    char FileName[20];
    int iRet = 0;

    if(argc!=2)
    {
        printf("INSUFFICIENT ARGUMENTS....\n");
        return -1;
    }  

    printf("ENTER THE FILE TO STORE DATA:");
    scanf("%s",FileName);  

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY...\n");
        return -1;
    }

    fd = creat(FileName,0777);
    if(fd == -1)
    {
        printf("UNABLE TO CREATE FILE...\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        sprintf(path,"%s/%s",argv[1],entry->d_name);
        stat(path,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            dprintf(fd,"FILENAME: %s,   INODE NO:%ld,   MODE: %ld,  SIZE OF FILE:%ld,   FILE CREATION TIME:%ld,%ld\n",entry->d_name,sobj.st_ino,sobj.st_mode,sobj.st_size,sobj.st_atime, sobj.st_mtime);
        }       
    }

    return 0;
}