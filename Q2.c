
#include <stdio.h>

int main() {
    printf("2.Write a program in C to find the sum of the left diagonals of a matrix.
.\n");
    printf("enter number of elements in matrix ");
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int r[n],c[n];
    printf("the matrixis \n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    int s=0;
    for (int i=0;i<n;i++){
            s=s+arr[i][i];
        }
    printf("\n");
    printf("left diagolnal sums is %d ",s);

    return 0;
}
