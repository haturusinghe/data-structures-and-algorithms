#include <stdio.h>
#include "list_l.h"


void insertionSort(List* list){
    Node* fu;
    Node* ls;
    Node* current;
    Node* trailing;

    if(list->head){
        ls = list->head;
    }
    while(ls->next){
        fu=ls->next;
        if(fu->value < list->head->value){
            ls->next = fu->next;
            fu->next = list->head;
            list->head = fu;
        }else{
            trailing = list->head;
            for(current = trailing->next; current->value < fu->value; current = current->next){
                trailing = current;
            }
            if(fu == current){
                ls = fu;
            }else{
                ls->next = fu->next;
                fu->next = current;
                trailing->next = fu;
            }
        }
    }
}