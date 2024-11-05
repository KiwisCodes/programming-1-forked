#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(struct Node** head, int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node** head, int data)//push_back
{
    struct Node* curNode = *head;
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;    
    if(*head == NULL) 
    {
        *head = newNode;
        return;
    }
    while(curNode->next != NULL) curNode = curNode->next;
    curNode->next = newNode;
    
}
//1 2 3, if insert 4 at 3 then 1 2 4 3


void insertAtPosition(struct Node** head, int data, int position)
{
    struct Node* newNode = createNode(data);
    if(position<=0)
    {
        printf("Index out of range\n");
        return;
    } 
    if(position == 1)
    {
        if(*head == NULL)
        {
            *head = newNode;
            return;
        }
        else
        {
            newNode->next = *head;
            *head = newNode;
        }
    }
    struct Node* curNode = *head;
    int pos = 1;
    while(curNode->next!=NULL && pos<position-1)
    {
        curNode = curNode->next;
        pos++;//this while loop stops when pos gets to postion or pos == position
    }
    if(curNode->next==NULL && pos != position)
    {
        free(newNode);
        printf("Index out of range\n");
        return;
    }
    struct Node* nextNode = curNode->next;
    curNode->next = newNode;
    newNode->next = nextNode;
}

void deleteFirst(struct Node** head)
{
    struct Node* lastHead = *head;//ask the teacher how to free the previous head
    *head = (*head)->next;
    free(lastHead);
}

void printLinkedList(struct Node* head)
{
    struct Node* curNode = head;
    while(curNode->next!=NULL)
    {
        printf("%d -> ", curNode->data);
        curNode = curNode->next;
    }
    printf("%d\n", curNode->data);
}



int main()
{
    struct Node* head = NULL;
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertAtPosition(&head, -1,2);

    printLinkedList(head);
    insertFirst(&head, -100);
    printLinkedList(head);
    deleteFirst(&head);
    printLinkedList(head);

}