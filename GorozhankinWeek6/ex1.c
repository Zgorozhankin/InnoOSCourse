#include <stdio.h>

int main()
{
    int n;
    printf("Enter total number of processes: ");
    scanf("%d",&n);
    int at[n], bt[n], wt[n], tat[n], ct[n], avwt = 0, avtat = 0;
 
    for(int i=0; i<n; i++) {
        printf("Enter process %d Arrival Time ", i+1);
        scanf("%d",&at[i]);
        printf("Enter process %d Burst Time ", i+1);
        scanf("%d",&bt[i]);
    }
 
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
        printf("P[%d]: Arrival Time %d, Completion Time %d, Burst Time, %d, Waiting Time %d, Turnaround Time %d\n", i+1, at[i], ct[i], bt[i], wt[i], tat[i]);
 
    printf("\n\nAverage Waiting Time: %f", (double)avwt/n);
    printf("\nAverage Turnaround Time: %f", (double)avtat/n);
 
    return 0;
}