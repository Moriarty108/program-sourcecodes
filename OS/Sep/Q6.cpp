#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(){
    
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    /* create the pipe */
    if(pipe(fd) < 0){
        fprintf(stderr, "Pipe failed");
    }

    /*fork a child process */
    pid = fork();

    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if(pid > 0){
        /* parent process */

        /*Close the unused end of the pipe */
        close(fd[READ_END]);

        /* write to the pipe */
        write(fd[WRITE_END], write_msg , strlen(write_msg) + 1);

        /* close the read end of the file */
        close(fd[WRITE_END]);
    }

    else{
        /* Child Process */

        close(fd[WRITE_END]);

        /* Read from the pipe */
        read(fd[READ_END], read_msg , BUFFER_SIZE);
        printf("read %s\n", read_msg);
        close(fd[READ_END]);
    }
    return 0;
}