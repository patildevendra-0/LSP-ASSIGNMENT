#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char* argv[])
{
    char DirName[20];
    char FileName[20];

    DIR *dp = NULL;
    struct dirent *entry = NULL;

    printf("ENTER THE DIRECTORY NAME...\n");
    scanf("%s",DirName);

    printf("ENTER THE FILE NAME WHICH YOU WANT CHECK PRESENT OR NOT :\n");
    scanf("%s",FileName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY...\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {
        if((strcmp(FileName,entry->d_name))==0)
        {
            printf("FILE IS PRESENT ...\n");
            break;
        }
    }
    if(entry == NULL)
    {
        printf("FILE IS NOT PRESENT IN DIRECTORY...\n");
        return -1;
    }



    return 0;
}