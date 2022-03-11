#include "numbers-game-assignment-1/stack.h"
#include <stdio.h>
#include <conio.h>

int main(void){
    Stack S;
    int i;
    char top;
    char str[50];
    CreateStack(&S);

    printf("Enter String: ");
    scanf("%[^\n]",str);

    for(i = 0; str[i] != '\0'; i++){
        if(!isStackFull(&S)){
           
            if(str[i] == ')'){
                Pop(&top,&S);
                int count = 0;
                while(top != '('){
                    count++;
                    Pop(&top,&S);
                }
                if(count < 1){
                    printf("Duplicate parenthesis found in the expression %s",str);
                    exit(1);
                }
            }else{
                Push(str[i],&S);
            }
        }
    }
    printf("No duplicate parenthesis found in the expression %s",str);
    return 0;
}
