#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc ,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char DirName[30] ={'\0'};
    struct stat sobj;
    char path[30] = {'\0'};

    printf("ENTER THE DIRECTORY NAME :\n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY..\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {
  
    }

    return 0;
}