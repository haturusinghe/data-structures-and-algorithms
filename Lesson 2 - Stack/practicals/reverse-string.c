#include "../headers/stack_c.h"

#include <stdio.h>
#include <conio.h>

int main(void){
    Stack S;
    int i;
    char c;
    char str[50];
    CreateStack(&S);

    printf("Enter String: ");
    scanf("%[^\n]",str);

    for(i = 0; str[i] != '\0'; i++){
        if(!isStackFull(&S)){
            printf("%c",str[i]);
            Push(&S,str[i]);
        }
    }
    printf("\nReversed String: ");
    while (!isStackEmpty(&S))
    {
        c = Pop(&S);
        putchar(c);
    }
    printf("\n");
    return 0;
}
