#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 512

int main()
{
    int Fd = 0;
    char Buffer[BLOCKSIZE];
    char * Path = "/tmp/mypipe1";

    Fd = open(Path,O_RDONLY);
    if(Fd == -1)
    {
        printf("UNABLE TO OPEN PIPE : \n");
        return -1;
    }

    read(Fd,Buffer,sizeof(Buffer));

    printf("DATA FROM PIPE : %s\n",Buffer);
    
    close(Fd);

    return 0;
}