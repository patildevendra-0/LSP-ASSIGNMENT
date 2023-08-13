#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    int SHMID = 0;
    int KEY = 1234;
    int SHMSIZE = 100;
    char *ptr = NULL;

    int iCnt = 0;
    int Length = 0;
    char Arr[] = "JAY GANESH";

    SHMID = shmget(KEY,SHMSIZE,IPC_CREAT|0666);
    if(SHMID != -1)
    {
        printf("SHARED MEMORY ALLOCATED SUCCESSFULLY : \n");
    }

    ptr = shmat(SHMID,NULL,0);
    if(ptr != NULL)
    {
        printf("SHARED MEMORY ATTACH SUCCESSFULLY...\n");
    }

    Length = strlen(Arr);

    for(iCnt = 0;iCnt<Length;iCnt++)
    {
        ptr[iCnt] = Arr[iCnt];
    }

    ptr[Length] = '\0';

    return 0;
}