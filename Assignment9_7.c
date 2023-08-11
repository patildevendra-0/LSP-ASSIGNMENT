#include<stdio.h>
#include<unistd.h>

int main()
{
    char * Username = NULL;

    Username = getlogin();
    printf("Logined User name:  %s\n",Username);

    return 0;
}