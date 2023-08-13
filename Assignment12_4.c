#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int iRet = 0;
    int Fd[2];
    char Arr[] = "SHREE GANESH";
    char Buffer[512];

    pipe(Fd);

    iRet = fork();
    if(iRet == 0)
    {
        printf("CHILD IS READY TO WRITE DATA IN PIPE : \n");
        close(Fd[0]);
        write(Fd[1],Arr,strlen(Arr));
    }
    else
    {
        printf("PARENT IS READY TO READ DATA FROM PIPE : \n");
        close(Fd[1]);
        read(Fd[0],Buffer,sizeof(Buffer));
    }

    printf("DATA FROM PIPE IS : %s\n",Buffer);

    return 0;
}