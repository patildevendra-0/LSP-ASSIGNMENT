#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 1024

int main()
{
    int fd = 0;
    int iRet = 0;
    int iCnt = 0;
    int iCount = 0;
    char Buffer[BLOCKSIZE];

    fd = open("Demo.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE ...\n");
        return -1;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(iCnt = 0;iCnt<iRet;iCnt++)
        {
            if(Buffer[iCnt]>='a' && Buffer[iCnt]<='z')
            {
                iCount++;
            }
        }
    }
    
    printf("Small letter count from file is: %d\n",iCount);

    return 0;
}