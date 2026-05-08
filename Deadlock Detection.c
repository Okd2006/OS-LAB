#include <stdio.h>

int main() {

    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m];
    int request[n][m];
    int available[m];


    printf("\nEnter Allocation Matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }


    printf("\nEnter Request Matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }


    printf("\nEnter Available Resources:\n");

    for(int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    int finish[n];
    int work[m];


    for(int i = 0; i < m; i++) {
        work[i] = available[i];
    }


    for(int i = 0; i < n; i++) {

        int zeroAllocation = 1;

        for(int j = 0; j < m; j++) {

            if(allocation[i][j] != 0) {
                zeroAllocation = 0;
                break;
            }
        }

        if(zeroAllocation)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    int changed = 1;

    while(changed) {

        changed = 0;

        for(int i = 0; i < n; i++) {


            if(finish[i] == 0) {

                int possible = 1;


                for(int j = 0; j < m; j++) {

                    if(request[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }


                if(possible == 1) {

                    printf("\nProcess P%d can execute", i);


                    for(int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    finish[i] = 1;
                    changed = 1;
                }
            }
        }
    }


    int deadlock = 0;

    printf("\n\nDeadlocked Processes: ");

    for(int i = 0; i < n; i++) {

        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("None");

    printf("\n");

    return 0;
}
