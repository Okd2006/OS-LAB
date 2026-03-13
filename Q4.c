#include <stdio.h>

int main() {
    printf("   4.Write a program in C to count the total number of duplicate elements in an array.\n");
    printf("enter number of elements in array ");
    int n;
    scanf("%d",&n);
    int arr[100];
    printf("enter elements");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    printf("Total number of duplicate elements: %d\n", count);

    return 0;
}
