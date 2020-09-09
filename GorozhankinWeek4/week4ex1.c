#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int n, pid, now;
	scanf("%d", &n);
    pid = getpid();
    fork();
    if (pid == getpid())
    	printf("Hello from parent %d\n", getpid() - n);
    else
    	printf("Hello from child %d\n", getpid() - n);

    return 0;
}