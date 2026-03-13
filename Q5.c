#include <stdio.h>

int main() {
    printf("   5.Write a program in C to find the second largest element in an array..\n");
    printf("enter number of elements in array ");
    int n;
    scanf("%d",&n);
    int arr[20];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int b1=-1000;
    int b2=-1000;
    for (int j=0;j<n;j++){
        if (arr[j]>b1){
            b2=b1;
            b1=arr[j];
        }
        else if (b2<arr[j] && b1!=arr[j]){
            b2=arr[j];
        }
    }
    printf("the second smallest element from the array is %d ",b2);
   
    return 0;
}
