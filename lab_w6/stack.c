
#include <stdlib.h>
#include <stdio.h>

/// @brief Implement stack using linked list

struct Node
{
    int data;
    struct Node* next;
};

struct Stack
{
    struct Node* top; // also be the head of the linked list
};

struct Node* createNode(int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack* stack, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack)
{
    int val = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return val;
}

// return 1 if the stack is empty otherwise 0
int is_empty(const struct Stack* stack)
{
    return stack->top == NULL;
}

int main()
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = NULL;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    while (!is_empty(stack))
    {
        printf("%d\n", pop(stack));
    }

    free(stack);

    return 0;
}