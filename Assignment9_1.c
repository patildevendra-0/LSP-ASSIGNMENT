#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main()
{
    int iRet = 0;

    iRet = fork();
    if(iRet == 0)
    {
        printf("CHILD PROCESS IS RUNNING ...\n");
        execl("Process1","NULL",NULL);
    }

    return 0;
}