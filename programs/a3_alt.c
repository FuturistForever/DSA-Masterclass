/*
Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
a)Find out the total number of duplicate elements.
b)Find out the most repeating element in the array.

Input:
Enter how many numbers you want to read from file: 15

Output:
The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
Total number of duplicate values = 4
The most repeating element in the array = 10 */

#include<stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n, i, j;
    printf("\nEnter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the elements:");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // printf("\nArray: ");
    // for (i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }

    bubbleSort(arr, n);

    // printf("\nSorted array: ");
    // for (i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }

    int curr;
    int no_dup = 0, curr_count;
    int max_count = 0;
    int most_rep = arr[0];
    i = 0;
    while(i<n){
        curr_count = 0;
        for (j = i + 1; j < n; j++){
            if(arr[i]==arr[j]){
                no_dup++;
                curr_count++;
            }
            break;
        }
        if(curr_count>max_count){
            max_count = curr_count;
            most_rep = arr[j - 1];
        }
        i = j;
    }

    printf("\nTotal no. of duplicates = %d", no_dup);
    printf("\nMost repeating element = %d", most_rep);

    return 0;
}