#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
    int iThreadId = 0;

    iThreadId = pthread_self();
    printf("ID OF THREAD FROM THREAD.....:%d\n",iThreadId);

    pthread_exit(NULL);
}

int main()
{
    int iRet = 0;
    pthread_t TID;

    iRet = pthread_create(&TID,NULL,ThreadProc,NULL);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD...\n");
        return -1;
    }
    
    printf("ID OF THREAD FROM MAIN FUNCTION.....:%d\n",TID);

    pthread_join(TID,NULL);

    return 0;
}