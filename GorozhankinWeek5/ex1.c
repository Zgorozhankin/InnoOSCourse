#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* printMessage(void* i){
    printf("Message from thread in iteration %d\n", *((int*)i));
    pthread_exit(NULL);
}

int main(){
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    pthread_t thread[n];
    
    for (i = 0; i < n; i++){
        pthread_create(thread + i, NULL, printMessage, (void*) &i);
        printf("Thread %d created in iteration %d\n", (int) thread[i], i);
        sleep(1);
    }
    
    return 0;
}
