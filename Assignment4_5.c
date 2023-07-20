#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc ,char *argv[])
{
    int fd = 0;
    int iRet = 0;
    char Buffer[20];

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE...\n");
        return -1;
    }

    iRet = read(fd,Buffer,10);
    if(iRet == 0)
    {
        printf("UNABLE TO READ DATA..\n");
        close(fd);
        return -1;
    }

    Buffer[iRet] = '\n';
    iRet++;
    write(1,Buffer,iRet);

    close(fd);
    return 0;
}