#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)();

    char FileName1[20];
    char FileName2[20];

    printf("ENTER THE FILE NAME: ");
    scanf("%s",FileName1);

    printf("ENTER THE FILE NAME: ");
    scanf("%s",FileName2);

    ptr = dlopen("/home/devendra/Desktop/LSP-ASSIGNMENT-1/FileCompare.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("UNABLE TO LOAD LIBRARY..\n");
        return -1;
    }

    fptr = dlsym(ptr,"FileCompare");
    if(fptr == NULL)
    {
        printf("UNABLE TO FETCH ADRESS OF FUNCTIOn..\n");
        return -1;
    }

    fptr(&FileName1,&FileName2);

    return 0;
}