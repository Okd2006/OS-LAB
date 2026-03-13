#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n],pr[n];
    int wt[n],tat[n],rt[n],ct[n],done[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter AT of P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter BT of P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Enter Priority of P%d: ",i+1);
        scanf("%d",&pr[i]);

        done[i]=0;
    }

    int time=0,completed=0;

    while(completed<n)
    {
        int best=9999,idx=-1;

        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && done[i]==0 && pr[i]<best)
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

        rt[idx]=time-at[idx];
        ct[idx]=time+bt[idx];
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];

        time=ct[idx];
        done[idx]=1;
        completed++;
    }

    float avgwt=0,avgtat=0,avgrt=0;

    printf("\nP\tAT\tBT\tPR\tWT\tTAT\tRT\n");

    for(int i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgtat+=tat[i];
        avgrt+=rt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],wt[i],tat[i],rt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
    printf("\nAverage Response Time = %.2f\n",avgrt/n);

    return 0;
}
