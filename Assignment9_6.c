#include<unistd.h>
#include<stdio.h>

int main()
{
    int iRet = 0;
    char Buffer[512];

    iRet = getlogin_r(Buffer,sizeof(Buffer));

    printf("login: %s\n",Buffer);
    return 0;
}