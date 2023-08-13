#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 512

int main()
{
    int Fd[2];
    int iret = 0;
    char Arr[] = "Marvellous Infosystem";
    char Buffer[BLOCKSIZE];

    pipe(Fd);

    iret = fork();
    if(iret == 0)
    {
        printf("Child Is Ready To Write Data In PIPE : \n");
        close(Fd[0]);
        write(Fd[1],Arr,strlen(Arr));
    }
    else
    {
        printf("Parent Is Ready To Read Data From PIPE : \n");
        close(Fd[1]);
        read(Fd[0],Buffer,sizeof(Buffer));
        printf("DATA FROM PIPE : %s\n",Buffer);
    }

    return 0;
}