#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t pid;
    /* fork a child process */
    pid = fork();
    if(pid < 0){
        /* error occurred */
        fprintf(stderr, "Fork Failed");
    }
    else if(pid == 0){
        /* child process */
        printf("Process execution Complete\n");
    }
    else{
        /* Parent process */
        printf("Process execution Complete\n");
    }
    return 0;
}