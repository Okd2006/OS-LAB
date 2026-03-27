#include<stdio.h>
struct Process{
int pid,at,bt,ct,tat,wt,rt;
};

int main(){
int n,tq;
struct Process p[20];
int queue[100];
int visited[20]={0};
int front=0,rear=0;
int time=0,completed=0;
int order[200];
int timeMark[201];
int k=0;
float avgwt=0,avgtat=0;

printf("Enter number of processes: ");
scanf("%d",&n);

for(int i=0;i<n;i++){
    p[i].pid=i+1;
    printf("\nProcess %d\n",i+1);
    printf("Arrival Time: ");
    scanf("%d",&p[i].at);
    printf("Burst Time: ");
    scanf("%d",&p[i].bt);
    p[i].rt=p[i].bt;
}


for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(p[i].at > p[j].at){
            struct Process temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
}

printf("\nEnter Time Quantum: ");
scanf("%d",&tq);

timeMark[0]=0;

while(completed<n){
    for(int i=0;i<n;i++){
        if(p[i].at<=time && visited[i]==0){
            queue[rear++]=i;
            visited[i]=1;
        }
    }

    if(front==rear){
        time++;
        continue;
    }

    int idx=queue[front++];
    order[k]=p[idx].pid;

    if(p[idx].rt>tq){
        p[idx].rt-=tq;
        time+=tq;
    }
    else{
        time+=p[idx].rt;
        p[idx].rt=0;
        p[idx].ct=time;
        p[idx].tat=p[idx].ct-p[idx].at;
        p[idx].wt=p[idx].tat-p[idx].bt;
        avgwt+=p[idx].wt;
        avgtat+=p[idx].tat;
        completed++;
    }

    k++;
    timeMark[k]=time;

    for(int i=0;i<n;i++){
        if(p[i].at<=time && visited[i]==0){
            queue[rear++]=i;
            visited[i]=1;
        }
    }

    if(p[idx].rt>0) queue[rear++]=idx;
}

printf("\n--- Round Robin Scheduling ---\n");
printf("\nGantt Chart:\n");
for(int i=0;i<k;i++) printf("| P%d ",order[i]);
printf("|\n");
for(int i=0;i<=k;i++) printf("%-5d",timeMark[i]);
printf("\n\n");

printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}

printf("\nAverage TAT = %.2f",avgtat/n);
printf("\nAverage WT = %.2f\n",avgwt/n);

return 0;
}
