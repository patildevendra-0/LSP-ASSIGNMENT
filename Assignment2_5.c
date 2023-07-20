#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc ,char *argv[])
{

    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char DirName[20];
    int iMax = 0;
    struct stat sobj;
    char path[30];
    char namecopy[20];

    printf("ENTER THE DIRECTORY NAME:\n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY....\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        sprintf(path,"%s/%s",DirName,entry->d_name);
        stat(path,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(iMax<sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(namecopy,path);
            }
        }
    }
    printf("NAME OF LARGEST FILE WITH SIZE :%s %d\n",namecopy,iMax);

    return 0;
}