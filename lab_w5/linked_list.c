#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node * next;
};

// insert a node with data to the end of the list
void push_back(struct Node * head, int data)
{   
    struct Node * currentNode = head;

    if(currentNode == NULL)
    {
        currentNode->data = data;
        currentNode->next = NULL;
    }
    else
    {
        while(currentNode->next!=NULL)
        {
            currentNode = currentNode->next;
        }
        struct Node * newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        currentNode->next = newNode;
    }
}


struct Node * toLinkedList(int * data_arr, int N)
{
    struct Node * head = malloc(sizeof(struct Node));

    // for element in array
    for(int i =0;i<N;i++)
    {
        push_back(head, data_arr[i]);
    }
    // push_back(head, element)

    return head;
}

void printNode(struct Node * head)
{
    if(head->next == NULL) return;
    else 
    {
        struct Node * currentNode = head;
        while(currentNode->next!=NULL)
        {
            printf("%d ->", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("%d", currentNode->data);
    }
}

int * getData(struct Node * head)
{
    int *out = NULL;
    int size = 0;

    while (/* condition */)
    {
        size ++;
        out = realloc(out, size * sizeof(int));
        /* code */
    }

    return out;
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    struct Node * linked_list = toLinkedList(arr, 5);
    printNode(linked_list);

    return 0; // set break point
}

