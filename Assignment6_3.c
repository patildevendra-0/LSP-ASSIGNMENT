#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc ,char * argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char FileName[20];
    char DirName[20];
    int fd = 0;
    char path[100];

    printf("ENTER THE DIRECTORY: ");
    scanf("%s",DirName);

    printf("ENTER THE FILE NAME TO CREATE FILE: ");
    scanf("%s",FileName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("unable to open directory..\n");
        return -1;
    }

    sprintf(path,"%s/%s",DirName,FileName);

    fd = creat(path,0777);
    if(fd == -1)
    {
        printf("UNABLE TO CREATE FILE..\n");
        return -1;
    }



    return 0;
}