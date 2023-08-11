#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int iCnt = 1;
pthread_mutex_t lock;

void * ThreadProc(void *)
{
    pthread_mutex_lock(&lock);
    printf("Counter Initially %d\n",iCnt);
    iCnt++;
    for(int i = 0;i<0xFFFFFFFF;i++);
    printf("Counter after: %d\n",iCnt);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main()
{

    int iRet = 0;
    pthread_t TID1,TID2;
    pthread_mutex_init(&lock,NULL);

    iRet = pthread_create(&TID1,NULL,ThreadProc,NULL);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }


    iRet = pthread_create(&TID2,NULL,ThreadProc,NULL);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}