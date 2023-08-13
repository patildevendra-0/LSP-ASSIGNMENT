#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

#define BLOCKSIZE 512

int main()
{
    int SHMID = 0;
    int KEY = 1234;
    int SHMSIZE = 100;
    char *ptr = NULL;
    char Buffer[BLOCKSIZE];
    int iCnt = 0;

    SHMID = shmget(KEY,SHMSIZE,0666);
    if(SHMID != -1)
    {
        printf("SHARED MEMORY ALLOCATED SUCCESSFULLY : \n");
    }

    ptr = shmat(SHMID,NULL,0);
    if(ptr != NULL)
    {
        printf("SHARED MEMORY ATTACH SUCCESSFULLY...\n");
    }

    while(ptr[iCnt] != '\0')
    {
        Buffer[iCnt] = ptr[iCnt];
        iCnt++;
    }
    printf("DATA FROM SHARED MEMORY : %s\n",Buffer);

    return 0;
}