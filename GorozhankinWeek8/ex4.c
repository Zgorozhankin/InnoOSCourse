#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

// Size of alocated memory in byte
#define SIZE 10485760

int main(){
    struct rusage usage;
    for (size_t i = 0; i < 10; i++) {
        memset(malloc(SIZE), '0', SIZE);

        getrusage(RUSAGE_SELF, &usage);
            printf("Used: %d\n", usage.ru_maxrss);
        
        sleep(1);
    }

    return 0;
}
