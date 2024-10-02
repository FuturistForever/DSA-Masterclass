/*
WAP to find out the second smallest and second largest element stored in an array of n integers. 
Input: Size of the array is 'n' and read 'n' number of elements from a disc file. 
Output: Second smallest, Second largest */

#include<stdio.h>

int main(){
    int n, i, second_smallest, second_largest, smallest=5000, largest=-5000;
    int arr[100];

    printf("\nEnter n: ");
    scanf("%d", &n);

    printf("\nEnter the elements:");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    second_smallest = smallest;
    second_largest = largest;

    smallest = arr[0];
    largest = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } 
        else if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }
        if (arr[i] > smallest && arr[i] < second_smallest) {
            second_smallest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest) {
            second_largest = arr[i];
        }
        
    }

    printf("\nSecond smallest = %d", second_smallest);
    printf("\nSecond largest = %d", second_largest);

    return 0;
}