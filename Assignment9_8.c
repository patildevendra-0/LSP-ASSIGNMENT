#include<stdio.h>
#include<unistd.h>


int main()
{
    char username[10];

    cuserid(username);
    printf("login %s\n",username);

    return 0;
}