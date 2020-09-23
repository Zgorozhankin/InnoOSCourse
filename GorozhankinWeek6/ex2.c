#include <stdio.h>

void swap (int* a, int* b, int * c, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    
    temp = b[i];
    b[i] = b[j];
    b[j] = temp;
    
    temp = c[i];
    c[i] = c[j];
    c[j] = temp;
}

void sort (int* bt, int* at, int * index, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if ((at[j] > at[j + 1]) || (at[j] == at[j + 1] && bt[j] > bt[j + 1]))
                swap(bt, at, index, j, j + 1);
        }
    }
}

int main()
{
    int n;
    printf("Enter total number of processes: ");
    scanf("%d",&n);
    int index[n], at[n], bt[n], wt[n], tat[n], ct[n], avwt = 0, avtat = 0;
 
    for(int i=0; i<n; i++) {
        printf("Enter process %d Arrival Time ", i+1);
        scanf("%d",&at[i]);
        printf("Enter process %d Burst Time ", i+1);
        scanf("%d",&bt[i]);
        index[i] = i + 1;
    }
    
    sort(bt, at, index, n);
 
    wt[0]=0;
    ct[0]=0;
    tat[0]=bt[0];
    
    for(int i=1; i<n; i++) {
        wt[i]=0;
        ct[i]=0;
        for(int j=0; j<i; j++)
            wt[i]+=bt[j];
        wt[i] -= at[i];
        ct[i] += wt[i] + at[i];
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
    }

    for(int i=0; i<n; i++)
        printf("P[%d]: Arrival Time %d, Completion Time %d, Burst Time, %d, Waiting Time %d, Turnaround Time %d\n", index[i], at[i], ct[i], bt[i], wt[i], tat[i]);
 
    printf("\n\nAverage Waiting Time: %f", (double)avwt/n);
    printf("\nAverage Turnaround Time: %f", (double)avtat/n);

    return 0;
}