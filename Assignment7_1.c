#include<stdio.h>
#include<dlfcn.h>

int main()
{

    void * ptr = NULL;
    int (*fptr)();
    int iRet = 0;

    ptr = dlopen("/home/devendra/Desktop/LSP-ASSIGNMENT-1/arithmetic.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("UNABLE TO LOAD LIBRARY...\n");
        return -1;
    }

////////////////////////////////////////////////////////////////////////// ADDITION //////////////////////////

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("UNABLE TO FETCH ADRESS OF FUNXCTION\n");
        return -1;
    }

    iRet = fptr(10,20);
    printf("ADDITION IS: %d\n",iRet);

///////////////////////////////////////////////////////////////////////////// SUBSTRACTION /////////////////////////

    fptr = dlsym(ptr,"Substraction");
    if(fptr == NULL)
    {
        printf("UNABLE TO FETCH ADRESS OF FUNXCTION\n");
        return -1;
    }

    iRet = fptr(10,20);
    printf("Substraction IS: %d\n",iRet);

////////////////////////////////////////////////////////////////////////// MULTIPLICATION ////////////////////////////

    fptr = dlsym(ptr,"Multiplication");
    if(fptr == NULL)
    {
        printf("UNABLE TO FETCH ADRESS OF FUNXCTION\n");
        return -1;
    }

    iRet = fptr(10,20);
    printf("MULTIPLICATION IS: %d\n",iRet);

/////////////////////////////////////////////////////////////////////////// DIVISION ///////////////////////////

    fptr = dlsym(ptr,"Division");
    if(fptr == NULL)
    {
        printf("UNABLE TO FETCH ADRESS OF FUNXCTION\n");
        return -1;
    }

    iRet = fptr(20,10);
    printf("DIVISION IS: %d\n",iRet);

    return 0;

}