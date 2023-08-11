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
    int iCnt = 0;

    pthread_t TID[4];

    void*(*Functions[4])(void*) = {ThreadProc1,ThreadProc2,ThreadProc3,ThreadProc4};

    for(iCnt = 0;iCnt<4;iCnt++)
    {
        pthread_create(&TID[iCnt],NULL,Functions[iCnt],NULL);
    }

    for(iCnt=0;iCnt<4;iCnt++)
    {
        printf("ID OF THREAD-%d : %d\n",iCnt,TID[iCnt]);
        pthread_join(TID[iCnt],NULL);
    }

    return 0;
}