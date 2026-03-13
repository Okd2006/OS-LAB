
#include <stdio.h>

int main() {
    printf("   3.Write a program in C to find the sum of rows and columns of a matrix.\n");
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
    int s1,s2=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            s1=s1+arr[i][j];
            s2=s2+arr[j][i];
        }
        r[i]=s1;
        s1=0;
        c[i]=s2;
        s2=0;
    }
    printf("row sums ");
    for (int i=0;i<n;i++){
        printf("%d ",r[i]);
    }
    printf("\n");
    printf("coloumn sums ");
    for (int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
    return 0;
}
