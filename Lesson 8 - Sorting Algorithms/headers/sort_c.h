

#include "list_c.h"

//INSERTION SORT
void insertSort(List* l){
    for(int i = 1; i < listSize(l); i++){
        int temp = l->items[i];
        int j = i - 1;
        while(j >=0 && l->items[j] > temp){
            l->items[j+1] = l->items[j];
            j--;
        }
        l->items[j+1] = temp;
    }
}

//SELECTION SORT (CONT)
void selectionSort(List* l){
    int smallest,i,j;
    for(i = 0; i < listSize(l); i++){
        smallest = i;
        for(j = i + 1; j < listSize(l); j++){
            if(l->items[j] < l->items[smallest]){
                smallest = j;
            }
        }
        int temp = l->items[i];
        l->items[i] = l->items[smallest];
        l->items[smallest] = temp; 
    }
}
//BUBBLE SORT
void bubbleSort(List *l){
    for (int j = 1; j < listSize(l); j++)
    {
        int flag = 0;
        for(int i = 0; i < listSize(l) - j;i++){
            if(l->items[i] > l->items[i+1]){
                int temp = l->items[i];
                l->items[i] = l->items[i+1];
                l->items[i+1] = temp; 
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}


void swapList(List* l, int a, int b){
        int temp = l->items[a];
        l->items[a] = l->items[b];
        l->items[b] = temp; 
}
