#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

extern char ** environ;
#define BLOCKSIZE 1024

int main()
{
    char **env = environ;
    char Buffer[BLOCKSIZE];
    int fd  = 0;

    fd = creat("FileEnvironment.txt",0777);
    if(fd == -1)
    {
        printf("UNABLE TO CREATE FILE..\n");
        return -1;
    }

    size_t env_len = strlen(*env);                   // size_t = unsigned long int

    while(*env!=NULL)
    {
        printf("%s\n",*env);
        env++;
        write(fd,*env,env_len);
    }
    
}