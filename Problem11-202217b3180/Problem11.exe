/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int target) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        if (arr[i] == target) 
        { 
            return i; // Element found at index i 
        } 
    } 
    return -1; // Element not found 
} 

int main() 
{ 
    int arr[] = {10, 2, 8, 5, 17}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target = 8; 
    int result = linearSearch(arr, n, target); 
    
    if (result == -1) 
    { 
        printf("Element not found in the array.\n"); 
    } 
    else 
    { 
        printf("Element found at index: %d\n", result); 
    } 
    
    return 0; 
}