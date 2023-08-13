#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{   
    int Fd = 0;
    char * Path = "/tmp/mypipe1";
    char Arr[] = "SHREE GANESH";

    Fd = mkfifo(Path,0666);
    if(Fd == -1)
    {
        printf("UNABLE TO CREATE PIPE..\n");
        return -1;
    }

    Fd = open(Path,O_WRONLY);
    if(Fd == -1)
    {
        printf("UNABLE TO OPEN PIPE...\n");
        return -1;
    }

    write(Fd,Arr,strlen(Arr));

    close(Fd);

    unlink(Path);

    return 0;
}