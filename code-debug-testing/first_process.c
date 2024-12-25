#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{

    int pid = getpid();

    int addedPid = pid + 114514;

    int correctPid = addedPid - 114514;

    printf("hello, this is process 1! pid is %d\n",correctPid);

    execl("./second_process", "second_process", (char *)NULL);

    return 0;
}