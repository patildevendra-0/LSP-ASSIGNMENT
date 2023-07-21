#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int argc,char *argv[])
{
    int fd = 0;
    char FileName[20];
    int iRet = 0;
    char Buffer[20];

    printf("ENTER THE FILE NAME: ");
    scanf("%s",FileName);
    
    fd = open(FileName,O_RDONLY);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE..\n");
        return -1;
    }

    iRet = read(fd,Buffer,sizeof(Buffer));

    lseek(fd,1024,SEEK_END);


    return 0;
}