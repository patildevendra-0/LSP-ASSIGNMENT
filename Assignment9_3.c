#include<stdio.h>
#include<sys/resource.h>

int main()
{
    int iRet = 0;

    iRet = getpriority(PRIO_PROCESS,0);
    printf("PRIORITY OF CURRENT PROCESS IS : %d\n",iRet);

    iRet = setpriority(PRIO_PROCESS,0,10);
    if(iRet == 0)
    {
        printf("Priority of process is : %d\n",iRet);
    }
    else
    {
        printf("Priority of process is NOT SET");
    }

    

    return 0;
}
