#include <stdio.h>


void FIFO(int pages[], int n, int f) {
    int frames[10], i, j, k = 0, found, faults = 0;

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\n--- FIFO ---\n");

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;

            printf("Page %d -> ", pages[i]);
            for(j = 0; j < f; j++)
                printf("%d ", frames[j]);
            printf("(Fault)\n");
        } else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("Total Page Faults (FIFO): %d\n", faults);
}


void LRU(int pages[], int n, int f) {
    int frames[10], time[10];
    int i, j, found, faults = 0;
    int counter = 0, pos, min;

    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\n--- LRU ---\n");

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found) {
            min = time[0];
            pos = 0;

            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            counter++;
            frames[pos] = pages[i];
            time[pos] = counter;
            faults++;

            printf("Page %d -> ", pages[i]);
            for(j = 0; j < f; j++)
                printf("%d ", frames[j]);
            printf("(Fault)\n");
        } else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("Total Page Faults (LRU): %d\n", faults);
}



void OPTIMAL(int pages[], int n, int f) {
    int frames[10];
    int i, j, k, found, faults = 0;
    int pos, farthest;

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\n--- OPTIMAL ---\n");

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            pos = -1;
            farthest = -1;

            for(j = 0; j < f; j++) {
                int nextUse = -1;

                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }

                if(nextUse == -1) {
                    pos = j;
                    break;
                }

                if(nextUse > farthest) {
                    farthest = nextUse;
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            faults++;

            printf("Page %d -> ", pages[i]);
            for(j = 0; j < f; j++)
                printf("%d ", frames[j]);
            printf("(Fault)\n");
        } else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("Total Page Faults (Optimal): %d\n", faults);
}



int main() {
    int pages[50], n, f, i;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    FIFO(pages, n, f);
    LRU(pages, n, f);
    OPTIMAL(pages, n, f);

    return 0;
}
