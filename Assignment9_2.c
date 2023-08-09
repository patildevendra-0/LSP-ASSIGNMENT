#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet1 = 0;
    int iRet2 = 0;

    iRet1 = fork();
    if(iRet1 == 0)
    {
        execl("Capital","NULL",NULL);
    }

    iRet2 = fork();
    if(iRet2 == 0)
    {
        execl("Small","NULL",NULL);
    }

    return 0;
}