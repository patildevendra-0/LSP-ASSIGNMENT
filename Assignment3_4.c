#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc ,char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char Path[50];

    printf("ENTER THE DIRECTORY NAME TO DELETE ALL EMPTY FILES FROMM THAT DIRECTORY:\n ");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY..\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        sprintf(Path,"%s/%s",DirName,entry->d_name);
        stat(Path,&sobj);
        if(sobj.st_size == 0)
        {
            remove(Path);
        }
    }

    closedir(dp);
    return 0;
}