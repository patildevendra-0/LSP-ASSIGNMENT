#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int dp = 0;

    dp = mkdir(argv[1],0777);
    if(dp == -1)
    {
        printf("UNABLE TO CREATE DIRECTORY..\n");
        return -1;
    }
    else
    {
        printf("SUCCESSLLY CREATED DIRECORY..\n");
    }
    

    return 0;
}