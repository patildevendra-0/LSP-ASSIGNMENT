#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    int iNo = (int)ptr;
    printf("value from main thread ---%d\n",iNo);
    pthread_exit(++iNo);
}

int main()
{
    int iRet = 0;
    pthread_t TID;
    int iValue = 21;
    int iret = 0;

    iRet = pthread_create(&TID,NULL,ThreadProc,(int *)iValue);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }

    pthread_join(TID,&iret);

    printf("Value from Thread ----%d\n",iret);

    return 0;
}