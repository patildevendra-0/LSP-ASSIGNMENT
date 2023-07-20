#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
    int fd = 0;
    char Buffer[BLOCKSIZE] = {'\0'};
    int iRet = 0;

    if(argc!=2)
    {
        printf("INSUFFICIENT ARGUMNETS....\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE..\n");
        return-1;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer))))
    {
        write(1,Buffer,iRet);
        memset(Buffer,0,sizeof(Buffer));
    }

    return 0;
}