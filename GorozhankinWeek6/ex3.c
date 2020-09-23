#include<stdio.h> 
 
int main() 
{
    int n, quantum;
    printf("Enter Total Process: "); 
    scanf("%d",&n);
    printf("Enter Time Quantum: "); 
    scanf("%d",&quantum);
    
    int at[n], bt[n], wt[n], tat[n], ct[n], rt[n], avwt = 0, avtat = 0;
    
    for(int i=0; i<n; i++) {
        printf("Enter process %d Arrival Time ", i+1);
        scanf("%d",&at[i]);
        printf("Enter process %d Burst Time ", i+1);
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
    }
    
    int time = 0, finished = 0;
    
    while(finished != n){
        for (int i = 0; i < n; i++){
            if (rt[i] > quantum){
                rt[i] -= quantum;
                time += quantum;
            } else if (rt[i] > 0){
                time += rt[i];
                ct[i] = time;
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];
                rt[i] = 0;
                finished++;
                avwt += wt[i];
                avtat += tat[i];
            }
        }
    }

    for(int i=0; i<n; i++)
        printf("P[%d]: Arrival Time %d, Completion Time %d, Burst Time, %d, Waiting Time %d, Turnaround Time %d\n", i + 1, at[i], ct[i], bt[i], wt[i], tat[i]);

    printf("\n\nAverage Waiting Time: %f", (double)avwt/n);
    printf("\nAverage Turnaround Time: %f", (double)avtat/n);
    
    return 0;
}