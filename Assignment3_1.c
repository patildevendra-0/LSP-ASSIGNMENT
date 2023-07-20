#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    char SourceFile[20];
    char DestFile[20];
    int fds = 0;
    int fdd = 0;
    char Buffer[BLOCKSIZE] = {'\0'};
    int iRet = 0;

    printf("ENTER THE SOURCE FILE NAME :\n");
    scanf("%s",SourceFile);

    printf("ENTER THE FILE NAME TO CREATE:\n");
    scanf("%s",DestFile);

    fds = open(SourceFile,O_RDONLY);
    if(fds == -1)
    {
        printf("UNABLE TO OPEN FILE ...\n");
        return -1;
    }

    fdd = creat(DestFile,0777);
    if(fdd ==-1)
    {
        printf("UNABLE TO CREATE NEW FILE...\n");
        return -1;
    }

    while((iRet = read(fds,Buffer,sizeof(Buffer)))!=0)
    {
        write(fdd,Buffer,iRet);
        memset(Buffer,0,sizeof(Buffer));
    }

    close(fds);
    close(fdd);

    return 0;
}