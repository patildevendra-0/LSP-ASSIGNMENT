#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

int main()
{
    int ShmId = 0;
    int Key = 1234;
    int ShmSize = 100;
    char * ptr = NULL;

    ShmId = shmget(Key,ShmSize,IPC_CREAT|0666);
    if(ShmId != -1)
    {
        printf("SHARED MEMORY ALLOCATED SUCCESSFULLY..\n");
    }

    ptr = shmat(ShmId,NULL,0);
    if(ptr != NULL)
    {
        printf("SHARED MEMORY ATTACH SUCCESSFULLY...\n");
    }

    

    return 0;
}