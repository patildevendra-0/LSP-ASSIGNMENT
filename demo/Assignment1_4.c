#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc ,char *argv[])
{
    int fd = 0;
    int iRet = 0;
    char *Buffer = NULL;


    if(argc != 3)
    {
        printf("INSUFFICIENT ARGUMENTS...\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE...\n");
        return -1;
    }

    Buffer = (char *)malloc(sizeof(argv[2]));

    iRet = read(fd,Buffer,atoi(argv[2]));
    if(iRet == 0)
    {
        printf("UNABLE TO READ DATA FROM FILE...\n");
        return -1;
    }
    else
    {
        printf("DATA FROM FILE :%s\n",Buffer);
    }

    return 0;
}