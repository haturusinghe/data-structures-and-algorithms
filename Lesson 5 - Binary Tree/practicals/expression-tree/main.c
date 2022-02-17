#include <stdio.h>
#include "TreeNode.h"

#define MAXSTACK 50

TreeNode* stack[MAXSTACK];
int top = -1;

void push(TreeNode *n){
    printf("PUSH newnode:%p  |  value:%c\n",n,n->entry);
    stack[++top] = n;
    printf("CHECK STACK newnode:%p  |  value:%c\n\n",stack[top],stack[top]->entry);
}

TreeNode* pop(){
    TreeNode* n = stack[top--];
    printf("POP newnode:%p  |  value:%c\n\n",n,n->entry);
    return n;
}

TreeNode* createExpTree(char postfix[]){
    TreeNode* temp;
    TreeNode* et;
    for (int i = 0; i < strlen(postfix); i++){
        if(!isOperator(postfix[i])){
            temp = newNode(postfix[i]);
            // printf("newnode:%p  |  value:%c\n",temp,temp->entry);
            push(temp);
        }else{
            temp = newNode(postfix[i]);
            temp->right = pop();
            temp->left = pop();
            // printf("newnode:%p  |  value:%c\n",temp,temp->entry);
            // printf("newnode:%p  |  value:%c\n",temp->right,temp->right->entry);
            // printf("newnode:%p  |  value:%c\n",temp->left,temp->left->entry);
            push(temp);
        }
    }

    et = pop();
    // printf("Top newnode:%p  |  value:%c\n",et,et->entry);
    // printf("Top2 newnode:%p  |  value:%c\n",et->left,et->left->entry);
    // printf("Top3 newnode:%p  |  value:%c\n",et->right,et->right->entry);
    return et;
}


void printEntry(TreeEntry te){
    printf("%c",te);
}


int main(void){
    char postfix[] = "ab+";
    TreeNode* expTree = createExpTree(postfix);
    Postorder(expTree,printEntry);
    printf("\n");
    Preorder(expTree,printEntry);
    printf("\n");
    Inorder(expTree,printEntry);
    
}
    