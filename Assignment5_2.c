#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 1024

int main(int argc ,char *argv[])
{
    int fd = 0;
    char Fname[20] = {'\n'};
    char Buffer[BLOCKSIZE];
    int iRet = 0;

    printf("ENTER THE FILE NAME TO READ: ");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);
    if(fd ==-1)
    {
        printf("UNABLE TO OPEN FILE ..\n");
        return -1;
    }

    iRet = read(fd,Buffer,sizeof(Buffer));

    write(1,Buffer,iRet);
    
    return 0;
}