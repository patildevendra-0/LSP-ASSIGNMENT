#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

struct Student
{
    char StudentName[30];
    int RollNo;
    float Marks;
    int age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    sobj.age = 23;
    sobj.Marks = 87.56f;
    sobj.RollNo = 32;
    strcpy(sobj.StudentName,"Aakash");

    int fd = 0;
    char Fname[20] = {'\0'};

    printf("ENTER THE FILE NAME :");
    scanf("%s",Fname);
    
    fd = creat(Fname,0777);
    if(fd == -1)
    {
        printf("UNABLE TO CREATE FILE..\n");
        return -1;
    }
    
    write(fd,&sobj,sizeof(sobj));
    close(fd);

    return 0;
}
