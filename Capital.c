#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 1024

int main()
{
    int fd = 0;
    int iRet = 0;
    char Buffer[BLOCKSIZE];
    int iCnt = 0;
    int iCount = 0;

    fd = open("Demo.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE...\n");
        return 0;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(iCnt=0;iCnt<iRet;iCnt++)
        {
            if(Buffer[iCnt]>='A' && Buffer[iCnt]<='Z')
            {
                iCount++;
            }
        }
    }
    printf("Capital letters count from file is: %d\n",iCount);
    close(fd);
    return 0;
}