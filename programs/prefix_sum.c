/*
Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].

Input Array: 	3 	4 	5 	1	 2
Output Array: 	3 	7 	12 	13 	15
*/

#include<stdio.h>

void prefixSum(int n, int arr[], int preSum[]){
    preSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        preSum[i] = preSum[i - 1] + arr[i];
  }
}

int main(){
    int n, i;
    printf("\nEnter n: ");
    scanf("%d", &n);

    int arr[n];
    int preSum[n];

    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    prefixSum(n, arr, preSum);

    printf("\nPrefix sum array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", preSum[i]);
    }

    return 0;
}
