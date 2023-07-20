#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc ,char *argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int iRet = 0;

    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];
    
    struct stat sobj1,sobj2;

    char FileName1[20] = {'\0'};
    char FileName2[20] = {'\0'};

    printf("ENTER THE FILE NAMES TO CHECK THEY ARE IDENTICAL OR NOT..\n");
    scanf("%s",FileName1);

    printf("ENTER THE FILE NAMES TO CHECK THEY ARE IDENTICAL OR NOT..\n");
    scanf("%s",FileName2);

    fd1 = open(FileName1,O_RDONLY);
    fd2 = open(FileName2,O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("UNABLE TO OPEN FILE \n");
        return -1;
    }
    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);
    if(sobj1.st_size != sobj2.st_size)
    {
        printf("THE SIZE OF BOTH FILES IS DIFFERENT..\n");
        return -1;
    }

    while(iRet = read(fd1,Buffer1,sizeof(Buffer1))!= 0)
    {
        iRet = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,iRet)!= 0)
        {
            break;
        }
    }

    if(iRet == 0)
    {
        printf("BOTH FILES ARE IDENTICAL..\n");
    }
    else
    {
        printf("BOTH FILES ARE DIFFERENT..\n");
    }

    close(fd1);
    close(fd2);

    return 0;
}