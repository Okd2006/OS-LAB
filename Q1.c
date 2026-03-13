#include <stdio.h>

int main() {
    printf("    1. Write a program in C to find the second smallest element in an array.\n");
    printf("enter number of elements in array ");
    int n;
    scanf("%d",&n);
    int arr[20];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int s1=1000;
    int s2=1000;
    for (int j=0;j<n;j++){
        if (arr[j]<s1){
            s2=s1;
            s1=arr[j];
        }
        else if (s2>arr[j] && s1!=arr[j]){
            s2=arr[j];
        }
    }
    printf("the second smallest element from the array is %d ",s2);
   
    return 0;
}
