#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int myFile = open("ex1.txt", O_RDWR);
  struct stat myStat = {};
  if (fstat(myFile, &myStat)){
       return -1;
   }

  char *addr = mmap(NULL, myStat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);
  ftruncate(myFile, 18);
  strcpy(addr, "This is a nice day"); 
  return 0;
}