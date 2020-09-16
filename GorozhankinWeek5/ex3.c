#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000

int iter = 0;
int array[SIZE];

void* producer_func(void* arg) {
    while(true) {
        
        while(iter < 0 || iter > SIZE - 1)
            sleep(1);

        array[iter] = iter;
        iter++;
    }
}

void* consumer_func(void* arg) {
    int temp = 0;
    while(true) {
        while(iter <= 0 || iter > SIZE)
            sleep(1);
            
        if (temp++ % (10 * SIZE) == 0)
            printf("%d\n", array[iter - 1]);
        
        iter--;
        array[iter] = -1;
    }
}

int main(){
    pthread_t producer_t, consumer_t;
    pthread_create(&producer_t, NULL, producer_func, NULL);
    pthread_create(&consumer_t, NULL, consumer_func, NULL);

    return 0;
}
