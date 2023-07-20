#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc ,char *argv[])
{
    DIR *dp = NULL;
    struct stat sobj;
    struct dirent * entry = NULL;
    char DirName[20];
    int fd = 0;
    char Path[20];
    int iRet = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    printf("ENTER THE DIRECTIORY NAME: ");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp ==NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY...\n");
        return -1;
    }

    fd = creat("AllCombineData.txt",0777);
    if(fd ==-1)
    {
        printf("UNABLE TO CREATE FILE...\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {
        sprintf(Path,"%s/%s",DirName,entry->d_name);
        stat(Path,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            iRet = open(Path,O_RDONLY);
            read(iRet,Buffer,sizeof(Buffer));
            write(fd,Buffer,sizeof(Buffer));
            write(fd, "\nFile Name: ", 12);
            write(fd, entry->d_name, strlen(entry->d_name));
            write(fd, "\n\n", 2);
            memset(Buffer,0,sizeof(Buffer));
        }
    }

    return 0;
}