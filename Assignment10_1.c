#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void *)
{
    printf("SHREE GANESH....\n");
    pthread_exit(NULL);
}

int main()
{
    int iRet = 0;
    pthread_t TID;

    iRet = pthread_create(&TID,NULL,ThreadProc,NULL);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD..\n");
        return -2;
    }
    
    pthread_join(TID,NULL);


    return 0;
}