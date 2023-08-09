#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int iRet = 0;
    int fd = 0;
    char *path = "/home/user00032/Desktop/ls/demo.c";
    int iCnt = 0;
    char Buffer[] = "SHREE GANESH...\n";

    iRet = daemon(0,0);
    if(iRet == -1)
    {
        printf("UNABLE TO CREATE DAEMON PROCESS..\n");
        return -1;
    }

    fd = creat(path,0777);
    if(fd == -1)
    {
        printf("UNABLE TO CREATE FILE...\n");
        return -1;
    }

    while(iCnt!=1000)
    {
        write(fd,Buffer,sizeof(Buffer));

        sleep(5);
    }

    printf("Daemon process successfully stop..\n");

    return 0;
}