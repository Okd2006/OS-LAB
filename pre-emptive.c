#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n],pr[n];
    int rt[n],wt[n],tat[n],ct[n],start[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter AT of P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter BT of P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Enter Priority of P%d: ",i+1);
        scanf("%d",&pr[i]);

        rt[i]=bt[i];
        start[i]=-1;
    }

    int time=0,completed=0;

    while(completed<n)
    {
        int best=9999,idx=-1;

        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && pr[i]<best)
            {
                best=pr[i];
                idx=i;
            }
        }

        if(idx==-1)
        {
            time++;
            continue;
        }

        if(start[idx]==-1)
            start[idx]=time;

        rt[idx]--;
        time++;

        if(rt[idx]==0)
        {
            completed++;
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
        }
    }

    float avgwt=0,avgtat=0,avgrt=0;

    printf("\nP\tAT\tBT\tPR\tWT\tTAT\tRT\n");

    for(int i=0;i<n;i++)
    {
        int response=start[i]-at[i];

        avgwt+=wt[i];
        avgtat+=tat[i];
        avgrt+=response;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],wt[i],tat[i],response);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
    printf("\nAverage Response Time = %.2f\n",avgrt/n);

    return 0;
}
