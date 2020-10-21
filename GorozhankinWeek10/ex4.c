#include<stdlib.h>
#include<stdio.h>

int main(){
	FILE* file1 = fopen("/tmp/file1", 'r');
	struct stat fileStat;
	if (fstat(file1, &fileStat))
		return -1;
	printf("%d\n", int(fileStat.st_ino));
	return 0;
}