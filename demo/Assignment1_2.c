#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc!=3)
    {
        printf("INSUFFICIENT ARGUMENT....\n");
        return -1;
    }
    if(strcmp(argv[2],"Read")==0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write")==0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }

    fd = open(argv[1],Mode);
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE ...\n");
        return -1;
    }
    else
    {
        printf("SUCCESSSFULLY OPEN FILE WITH FD: %d AND MODE %d\n",fd,Mode);
    }

    return 0;
}