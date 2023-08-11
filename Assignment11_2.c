#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    printf("IN THREAD 1..\n");
    pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
    printf("IN THREAD 2..\n");
    pthread_exit(NULL);
}

void * ThreadProc3(void *ptr)
{
    printf("IN THREAD 3..\n");
    pthread_exit(NULL);
}

void * ThreadProc4(void *ptr)
{
    printf("IN THREAD 4..\n");
    pthread_exit(NULL);
}


int main()
{
    int iRet = 0;
    pthread_t TID1,TID2,TID3,TID4;

    iRet = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }


    iRet = pthread_create(&TID2,NULL,ThreadProc2,NULL);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }


    iRet = pthread_create(&TID3,NULL,ThreadProc3,NULL);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }


    iRet = pthread_create(&TID4,NULL,ThreadProc4,NULL);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    pthread_join(TID3,NULL);
    pthread_join(TID4,NULL);

    return 0;
}