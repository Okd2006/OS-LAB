#include <stdio.h>

int main() {
    printf("    6.Write a program in C to delete an element at a desired position from an array.\n");
    printf("enter number of elements in array ");
    int n;
    scanf("%d",&n);
    int arr[20];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int pos;
    printf("enter postion of elememt to delete ");
    scanf("%d",&pos);
    if (pos<0 || pos>n){
        printf("invalid position ");
        return 1;
    }

    for (int j=pos;j<n-1;j++){
        arr[pos]=arr[pos+1];
    }
     for (int i=0;i<n-1;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
