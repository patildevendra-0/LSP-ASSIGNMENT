#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    int iNo = (int*)ptr;
    printf("VALUE FROM MAIN FUNCTION...%d\n",iNo);
    pthread_exit(NULL);
}

int main()
{
    int iRet = 0;
    pthread_t TID;
    int iValue = 11;

    iRet = pthread_create(&TID,NULL,ThreadProc,(int *)iValue);
    if(iRet!= 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }

    pthread_join(TID,NULL);

    return 0;
}