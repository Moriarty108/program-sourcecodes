#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

#define BUFFER_SIZE 25
#define WRITE_END 1
#define READ_END 0

int main(int argc, char const *argv[])
{
    char write_msg[BUFFER_SIZE] = "Greetings!";
    char read_msg[BUFFER_SIZE];

    int fd[2];
    pid_t pid;
    

    if(pipe(fd) < 0){
        fprintf(stderr,"Pipe Error");
        _exit(-1);
    }
    pid = fork();
    if(pid < 0){
        fprintf(stderr,"Error Forking");
        _exit(-1);
    }

    else if(pid > 0){
        
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]);
    }

    else{
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Read msg : %s\n", read_msg);
        close(fd[READ_END]);
    }
    return 0;
}
