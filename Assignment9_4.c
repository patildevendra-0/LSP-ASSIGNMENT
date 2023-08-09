#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = 0;

    iRet = nice(1);
    if(iRet == -1)
    {
        printf("UNABLE TO SET PRORITY..\n");
        return -1;
    }
    
    printf("Priority of process is : %d\n",iRet);

    return 0;
}