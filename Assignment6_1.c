#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc,char *argv[])
{
    char DirName[20];
    char Path[20];

    DIR *dp = NULL;
    struct stat sobj;
    struct dirent * entry = NULL;

    printf("ENTER THE DIRECTORY NAME :");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY...\n");
        return -1;
    }
    
    while((entry = readdir(dp))!= NULL)
    {
        sprintf(Path,"%s/%s",DirName,entry->d_name);
        stat(Path,&sobj);

        if(S_ISREG(sobj.st_mode) && sobj.st_size > 10)
        {
            printf("FILENAME Greater then 10 bytes: %s\n",entry->d_name);
        }
    }

    closedir(dp);

    return 0;
}