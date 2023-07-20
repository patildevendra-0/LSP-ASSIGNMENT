#include<stdio.h>
#include<fcntl.h>

int main(int argc ,char *argv[])
{
    int fd = 0;
    
    if(argc!=2)
    {
        printf("INSUFFICIENT ARGUMENT....\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE...\n");
        return -1;
    }
    else
    {
        printf("SUCCESSFULLY OPEN FILE....\n");
    }

    return 0 ;
}