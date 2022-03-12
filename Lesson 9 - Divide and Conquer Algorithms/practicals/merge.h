#include "list.h"
#define LE(a,b) ((a) <= (b))


//Function prototypes
void Divide(List*,List*);
void Divide2(List*,List*);
void Merge(List * first, List * second, List * out);

void MergeSort(List* list) {

  List secondhalf; //hold the second half of the list after division
  if (listSize(list)> 1) // Is there a need to sort
  {
    //Divide the list in half
    Divide2(list, &secondhalf);
    // Sort the first half
    MergeSort(list);
    // Sort the second half 
    MergeSort(&secondhalf);
    // Merge the two sorted sublist
    Merge(list, &secondhalf, list);
  }
}

void Divide(List *list, List *secondhalf) {
  createList(secondhalf);
  Node* current, *midpoint;
  if ((midpoint = list -> head) == NULL){
    secondhalf-> head = NULL;
  } else {
    for (current = midpoint -> next; current;) {
      current = current -> next;
      if (current) {
        midpoint = midpoint -> next;
        current = current -> next;
      }
    }
    
    secondhalf->head = midpoint->next;
    midpoint->next = NULL;
  }
}

void Divide2(List *list, List *secondhalf) {
  createList(secondhalf);
  Node* current;

  if(list->head == NULL){
    secondhalf->head == NULL;
  }else{

    int mid = listSize(list) / 2;

    if(mid > 0){
      current = list->head;
      for(int i = 1 ; i < mid ; i++){
        current = current->next;
      }
      //printf("SecondHalf: %d FirstHalf End: %d \n",current->next->value,current->value);
      secondhalf->head = current->next;
      current->next = NULL;
    }else{
      secondhalf->head = current->next;
    }
  }

}

void Merge(List * first, List *second, List * out) {
  Node* p1, * p2; //pointers to traverse first and second lists
  Node* lastsorted; //always points to last node of sorted list

  if (!first -> head)
    *out = *second;
  else if (!second -> head)
    *out = *first;
  else {
    p1 = first -> head; //first find the head of the merged list
    p2 = second -> head;
    if (LE(p1->value, p2->value)) {
      *out = *first;
      p1 = p1 -> next;
    } else {
      *out = *second;
      p2 = p2 -> next;
    }

    lastsorted = out -> head;
    
    while (p1 && p2)
      if (LE(p1->value, p2->value)) {
        lastsorted -> next = p1;
        lastsorted = p1;
        p1 = p1 -> next;
      } else {
        lastsorted -> next = p2;
        lastsorted = p2;
        p2 = p2 -> next;
      }
    if (p1)
      lastsorted -> next = p1; // Attach the remaining list
    else
      lastsorted -> next = p2;
  }
}