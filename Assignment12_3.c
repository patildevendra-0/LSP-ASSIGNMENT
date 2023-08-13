#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

#define BLOCKSIZE 512

int main()
{
    int ShmId = 0;
    int Key = 1234;
    int ShmSize = 100;
    char Buffer[BLOCKSIZE];

    ShmId = shmget(Key,ShmSize,0666);
    if(ShmId != -1)
    {
        printf("SHARED MEMORY ALLOCATED SUCCESSFULLY...\n");
    }



    return 0;
}