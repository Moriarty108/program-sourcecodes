#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include<sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    const int size = 4096;
    const char *name ="OS";
    const char *msg_0 ="Hello";
    const char *msg_1 ="World";
    int shm_fd;
    void *ptr;
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, 4096);
    ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sprintf((char *)ptr,"%s", msg_0);
    ptr += strlen(msg_0);
    sprintf((char *)ptr,"%s", msg_1);
    ptr += strlen(msg_1);
    return 0;
}
