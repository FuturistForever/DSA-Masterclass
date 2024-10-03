/*
Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion. Store the binary value in a separate disc file. 

Note# Read the value of ‘n’, source file name and destination file name from command line arguments. Display the decimal numbers and their equivalent binary numbers from the output file. 

Give the contents of the input disc file “inDec.dat” as 
30  75   2564  …

Contents of the output disc file “outBin.dat” as 
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100 

Terminal Input:
$gcc lab2q1.c -o lab2q1
$./lab2q1 150 inDec.dat outBin.dat

Output: Content of the first ‘n’ decimal and their equivalent binary numbers 
*/
#include<stdio.h>
#include<string.h>

void toBin(int arr[], int n, int i){
    if(i==n)
        return;
    
    char binary[17];
    int j;
    for (j = 0; j < 16; j++){
        binary[j] = '0';
    }
    binary[j] = '\0';

    int temp = arr[i];
    j = 15;
    while(temp!=0){
        binary[j] = (temp % 2) + '0';
        temp /= 2;
        j--;
    }
    printf("\nThe binary equivalent of %d is ", arr[i]);
    puts(binary);
    i++;
    toBin(arr, n, i);
}

int main(){
    int n;
    printf("\nEnter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    toBin(arr,n,0);

    return 0;
}