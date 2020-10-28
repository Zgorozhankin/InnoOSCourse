#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    open("ex1.txt", O_RDWR);
    open("ex1.memcpy.txt", O_RDWR);

    struct stat mySt1 = {};
    struct stat mySt2 = {};
    if (fstat(file1, &mySt1) | fstat(file2, &mySt2)){
      return -1;
    }

    char *addr1 = mmap(NULL, mySt1.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file1, 0);
    char *addr2 = mmap(NULL, mySt2.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file2, 0);

    ftruncate(file2, strlen(addr1));
    memcpy(addr2, addr1, strlen(addr1));

    return 0;
}