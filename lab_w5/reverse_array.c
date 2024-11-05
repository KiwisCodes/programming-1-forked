#include <stdlib.h>
#include <stdio.h>

// define your swap function here

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c; 
}

// reverse array function
void reverse_array(int *arr, int N)
{
    // your code here
    for(int i = 0;i<N/2;i++)
    {
        swap(&arr[i], &arr[N-i-1]);
    }
    // use your swap function
    for(int i = 0;i<N;i++) printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    reverse_array(arr, 5);

    return 0; // set break point
}