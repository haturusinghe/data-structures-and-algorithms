#include <stdio.h>
#include <stdlib.h>

/*A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}Node;

/*Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/*Give a binary search tree and a number,
inserts a new node with the given number in
the correct place in the tree. Returns the new
root pointer which the caller should then use
(the standard trick to avoid using reference
parameters). */
Node* insert(Node *node, int data)
{
    /*1. If the tree is empty, return a new,    
        single node */
    if (node == NULL)
        return (newNode(data));
    else
    {
        /*2. Otherwise, recur down the tree */
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        /*return the (unchanged) node pointer */
        return node;
    }
}

/*Given a non-empty binary search tree, 
return the minimum data value found in that
tree. Note that the entire tree does not need
to be searched. */
int minValue(Node *node)
{
    Node *current = node;

    /*loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }

    return (current->data);
}

int sumTree(Node *node)
{
    Node *currentLeft = node;
    Node *currentRight = node;
    Node *temp = node;
    int leftSum =0;
    int rightSum =0;

    /*Adding Left tree */
    while (currentLeft->left != NULL)
    {
        leftSum = leftSum + currentLeft->data;
        currentLeft = currentLeft->left;
    }

    /*Adding Right tree */
    while (currentRight->right != NULL)
    {
        rightSum = rightSum + currentRight->data;
        currentRight = currentRight->right;
    }

    return (leftSum+rightSum);
}

/* Function to find sum of all the elements*/
int addBT(Node *root)
{
    if (root == NULL)
        return 0;
    return (root->data + addBT(root->left) + addBT(root->right));
}

/*Driver program to test sameTree function*/
int main()
{
    Node *root = NULL;
    root = insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 2);
    insert(root, 30);
    insert(root, 40);
    insert(root, 10);

    printf("\n Minimum value in BST is %d\n", minValue(root));
    printf("\n Sum of BST is %d\n", addBT(root));
    return 0;
}