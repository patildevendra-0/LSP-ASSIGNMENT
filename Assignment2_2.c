#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 20

int main(int argc, char *argv[])
{
    int fd = 0;
    int iRet = 0;
    char Data[BLOCKSIZE] = {'\0'};

    if(argc != 2)   
    {
        printf("INSUFFICIENT ARGUMNETS..\n");
        return -1;
    }
    
    printf("Enter the String:\n");
    scanf("%[^'\n']s",Data);

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE..\n");
        return -1;
    }

    write(fd,Data,strlen(Data));

    return 0;
}