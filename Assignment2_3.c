#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc ,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if(argc!=2)
    {
        printf("INSUFFICIENT ARGUMNETS..\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("UABLE TO OPEN DIRECTIORY...\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        printf("Entry from %s directory are: %s\n",argv[1],entry->d_name);
    }


    return 0;
}