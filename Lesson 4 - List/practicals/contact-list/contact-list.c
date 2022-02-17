#include "list_l.h"


int main(){
    List phonebook;
    createList(&phonebook);

    bool flag = true;
    char prompt;

    Contact temp;

    do{
        printf("Enter Name and Phone Number: ");
        scanf("%s %s",temp.name,temp.number);
        insertLast(&phonebook,temp);

        printf("\nContinue (Y|N) ?: ");
        getchar();
        prompt = getchar();
        getchar();
        if(prompt == 'N'){
            flag = false;
        }
        printf("\n");

    }while(flag);

    do{
        printf("Enter Name to remove: ");
        scanf("%[^\n]s ",temp.name);
        removeContact(&phonebook,temp);

        printf("\nContinue (Y|N) ?: ");
        getchar();
        prompt = getchar();
        getchar();
        if(prompt == 'N'){
            flag = false;
        }
        printf("\n");

    }while(flag);

    printList(&phonebook);
}