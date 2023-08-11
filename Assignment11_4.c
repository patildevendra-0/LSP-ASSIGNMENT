#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define BLOCKSIZE 512

void *ThreadProc1(void *ptr)
{
    int iCnt = 0;
    int iCount = 0;
    int iRet = 0;
    char Buffer[BLOCKSIZE];
    int FileId = *(int *)ptr;

    while ((iRet = read(FileId, Buffer, sizeof(Buffer))) != 0)
    {
        for (iCnt = 0; iCnt < iRet; iCnt++)
        {
            if (Buffer[iCnt] >= 'a' && Buffer[iCnt] <= 'z')
            {
                iCount++;
            }
        }
    }
    pthread_exit(iCount);
}

void *ThreadProc2(void *ptr)
{
    int iCnt = 0;
    int iCount = 0;
    int iRet = 0;
    char Buffer[BLOCKSIZE];
    int FileId = *(int *)ptr;

    while ((iRet = read(FileId, Buffer, sizeof(Buffer))) != 0)
    {
        for (iCnt = 0; iCnt < iRet; iCnt++)
        {
            if (Buffer[iCnt] >= 'A' && Buffer[iCnt] <= 'Z')
            {
                iCount++;
            }
        }
    }
    pthread_exit(iCount);
}

int main(int argc,char *argv[])
{
    int iRet = 0;
    int iret1,iret2 = 0;
    int Fd1, Fd2 = 0;

    pthread_t TID1, TID2;

    if(argc!=2)
    {
        printf("INSUFFICIENT ARGUMENTS...\n");
        return -1;
    }

    Fd1 = open(argv[1],O_RDONLY);
    if(Fd1 == -1)
    {
        printf("UNABLE TO OPEN FILE ...\n");
        return -1;
    }

    Fd2 = open(argv[1],O_RDONLY);
    if(Fd2 == -1)
    {
        printf("UNABLE TO OPEN FILE ...\n");
        return -1;
    }

    iRet = pthread_create(&TID1, NULL, ThreadProc1, &Fd1);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD..\n");
        return -1;
    }

    iRet = pthread_create(&TID2, NULL, ThreadProc2, &Fd2);
    if(iRet != 0)
    {
        printf("UNABLE TO CREATE THREAD..\n");
        return -1;
    }

    pthread_join(TID1,&iret1);
    pthread_join(TID2,&iret2);

    printf("SMALL LETTER COUNT FROM FILE - %s IS : %d\n",argv[1],iret1);
    printf("CAPITAL LETTER COUNT FROM FILE - %s IS : %d\n",argv[1],iret2);
    
    close(Fd1);
    close(Fd2);

    return 0;
}