#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include"FileCompare.h"


#define BLOCKSIZE 1024
int FileCompare(char * File1, char* File2)
{

    int fd1 = 0;
    int fd2 = 0;
    int iRet = 0;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];

    struct stat sobj1;
    struct stat sobj2;

  
    fd1 = open(File1,O_RDONLY);
    if(fd1 == -1)
    {
        printf("UNABLE TO OPEN  FILE...\n");
        return -1;
    }

    fd2 = open(File2,O_RDONLY);
    if(fd2 == -1)
    {
        printf("UNABLE TO OPEN ..\n");
        return -1;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("FILES ARE DIFFERENT AS SIZE OF FILE ARE DIFFERENT....\n");
        return -1;
    }

    while((iRet = read(fd1,Buffer1,sizeof(Buffer1)))!=NULL)
    {
        iRet = read(fd2,Buffer2,sizeof(Buffer2));
        
        if(memcmp(Buffer1,Buffer2,iRet)!=0)
        {
            break;
        }
        memset(Buffer1,0,sizeof(Buffer1));
        memset(Buffer2,0,sizeof(Buffer2));
    }    

    if(iRet == 0)
    {
        printf("BOTH FILES ARE IDENTICAl...\n");
    }
    else
    {
        printf("BOTH FILES ARE DIFFERENT..\n");
    }


    close(fd1);
    close(fd2);

}