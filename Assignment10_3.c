#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    printf("VALUE FROM MAIN FUNCTION...%d\n",*(int*)ptr);
    pthread_exit(NULL);
}

int main()
{
    int iRet = 0;
    pthread_t TID;
    int iValue = 11;

    iRet = pthread_create(&TID,NULL,ThreadProc,&iValue);

    pthread_join(TID,NULL);

    return 0;
}