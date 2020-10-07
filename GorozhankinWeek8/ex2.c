#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

// Size of alocated memory in byte
#define SIZE 10485760

int main(){
	for (size_t i = 0; i < 10; i++) {
		memset(malloc(SIZE), '0', SIZE);
		sleep(1);
	}

	return 0;
}