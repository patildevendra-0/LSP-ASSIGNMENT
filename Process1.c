#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
};

int main()
{
    int fd = 0;
    DIR * dp = NULL;
    struct dirent *entry = NULL;
    char * path = "/home/user00032/Desktop";
    char * filepath = "/home/user00032/Desktop/ls/demo.txt";

    struct FileInfo fobj;

    dp = opendir(path);
    if(dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY...\n");
        return -1;
    }

    fd = creat(filepath,0777);
    if(fd == -1)
    {
        printf("UNABLE TO CREATE FILE...\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        printf("%s\n",entry->d_name);
        strcpy(fobj.FileName,entry->d_name);
        write(fd,&fobj,sizeof(fobj));
    }
    closedir(dp);

    return 0;
}