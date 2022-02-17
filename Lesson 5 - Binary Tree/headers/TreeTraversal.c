#include <stdio.h>
#include <stdbool.h>

typedef char TreeEntry;

typedef struct treenode
{
    TreeEntry entry;
    struct treenode * left;
    struct treenode * right;
}

TreeNode;

void CreateTree(TreeNode **root)
{
    *root = NULL;
}

bool TreeEmpty(TreeNode *root)
{
    return (root == NULL);
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