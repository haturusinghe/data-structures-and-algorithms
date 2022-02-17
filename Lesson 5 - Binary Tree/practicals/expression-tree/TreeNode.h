#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char TreeEntry;

typedef struct treenode
{
    char entry;
    struct treenode * left;
    struct treenode * right;
}TreeNode;


bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '^'){
            return true;
        }
    return false;
}


TreeNode * newNode(TreeEntry v){
    TreeNode * temp = (TreeNode *)malloc(sizeof(struct treenode));
    if(temp){
        temp->left = NULL;
        temp->right = NULL;
        temp->entry = v;
    }
    return temp;
}

void Preorder(TreeNode *root, void(*Visit)(TreeEntry x))
{
    if (root)
    {
        Visit(root->entry);
        Preorder(root->left, Visit);
        Preorder(root->right, Visit);
    }
}

void Inorder(TreeNode *root, void(*Visit)(TreeEntry x))
{
    if (root)
    {
        Inorder(root->left, Visit);
        Visit(root->entry);
        Inorder(root->right, Visit);
    }
}



void Postorder(TreeNode *root, void(*Visit)(TreeEntry x))
{
    if (root)
    {
        Postorder(root->left, Visit);
        Postorder(root->right, Visit);
        Visit(root->entry);
    }
}
