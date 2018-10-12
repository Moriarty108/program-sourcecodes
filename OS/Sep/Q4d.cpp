#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    /* forking a child process with same address space */
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Error in forking\n");
    }
    else if (pid == 0)
    {
        /* Child Process */
        execlp("./p1", "p1", NULL);
    }
    else
    {
        /* Parent Process */
        wait(NULL);
        printf("Parent Process Complete\n");
    }
    return 0;
}