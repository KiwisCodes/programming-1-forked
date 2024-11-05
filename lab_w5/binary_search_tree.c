#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

/// @brief  function to create a node
struct Node * createNode(int data)
{
    struct Node * node = (struct Node*)malloc(sizeof (struct Node));
    node->data = data;
    node->left=node->right=NULL;
    return node;
}

/* build the following tree
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
struct Node * buildCustomTree()
{
    struct Node * root = createNode(50);
    root->left = createNode(30);
    root ->right = createNode(70);
    return root;
}

struct Node * insertNode(struct Node* root, int data)
{
    if(root != NULL) 
    {
        if(data <= root->data) root->left = insertNode(root->left, data);
        else root->right = insertNode(root->right, data);
    }
    else 
    {
        return createNode(data);
    }
    return root;
}

void freeMemory(struct Node * root)
{
    if(root == NULL) return;

    freeMemory(root->left);
    freeMemory(root->right);
    free(root); 
}

// A utility function to do inorder traversal of BST
void inorder(struct Node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main()
{
    struct Node * root = buildCustomTree();
    inorder(root);
    insertNode(root,90);
    inorder(root);

    freeMemory(root);
    return 0;
}