// copy your swap function from reverse_array.c
#include <stdio.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int *arr, int N)
{
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N-1;j++)
        {
            if(arr[j] >= arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
    }

    for(int i = 0;i<N;i++) printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {1, 4, 3, 7, -1};
    bubble_sort(arr, 5);

    return 0; // set break point
}