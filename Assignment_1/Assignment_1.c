
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};
//sth

struct Node* createNode(int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** p_head, struct Node* position, int data) 
{
    if(*p_head == NULL) 
    {
        *p_head = createNode(data);
        return;
    }
    struct Node* curNode = *p_head;
    while(curNode!=position) curNode = curNode->next;
    struct Node* prevNode = curNode;
    curNode = createNode(data);
    curNode->next = prevNode;
}

void pushBack(struct Node** p_head, int data)
{
    struct Node* curNode = *p_head;
    while(curNode->next != NULL) curNode = curNode->next;
    curNode->next = createNode(data);
}

void deleteNode(struct Node** p_head, struct Node* position) 
{
    if(position == *p_head)
    {
        *p_head = (*p_head)->next;
        return;
    }
    
    struct Node* curNode = *p_head;
    while(curNode->next != position) curNode = curNode->next;

    struct Node* nextNodeOfPosition = position->next;
    free(position);
    curNode->next = nextNodeOfPosition;

}

int sizeOfList(struct Node* head) 
{
    int count = 0;
    struct Node* curNode = head;
    while(curNode->next!=NULL) count++;

    return count;
}

void deleteList(struct Node **p_head)
{
    struct Node* curNode = *p_head;
    while(curNode->next!=NULL)
    {
        struct Node* nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
}

// Display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// display the linked list to a string output
void displayListToString(struct Node* head, char* output) {
    sprintf(output, "%s", "");
    struct Node* temp = head;
    while (temp != NULL) {
        char temp_str[100];
        sprintf(temp_str, "%d -> ", temp->data);
        strcat(output, temp_str);
        temp = temp->next;
    }
    // concatenate NULL to the output string
    sprintf(output, "%sNULL", output);
}

void printList(struct Node** head)
{
    struct Node* curNode = *head;
    while(curNode->next!=NULL)
    {
        printf("%d ",curNode->data);
        curNode = curNode->next;
    }
    return;
}

int main()
{
    struct Node* head = NULL;
    insertNode(&head, head, 10);
    printList(&head);
    return 0;
}


