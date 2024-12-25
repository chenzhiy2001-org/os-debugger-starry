#include <stdio.h>
#include <unistd.h>
int main(){
    printf("hello, this is process 2! pid is %d\n",getpid());
    return 0;
}