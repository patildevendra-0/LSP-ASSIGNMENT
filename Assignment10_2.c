#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc1(void *)
{
    int iCnt = 0;
    for(iCnt = 1;iCnt<=500;iCnt++)
    {
        printf("%d\n",iCnt);
    }

    pthread_exit(NULL);

}

void * ThreadProc2(void *)
{
    int iCnt = 500;
    for(iCnt = 500 ;iCnt!=1;iCnt--)
    {
        printf("%d\n",iCnt);
    }

    pthread_exit(NULL);

}


int main()
{

    int iRet1 = 0;
    int iRet2 = 0;

    pthread_t TID1;
    pthread_t TID2;


    iRet1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    iRet2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);


    return 0;
}