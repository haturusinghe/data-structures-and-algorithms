#include<stdio.h>  
#include "list_c.h"
#define LT(a,b) ((a) < (b))

//Function Protottypes
void RecQuickSort(List * list, Position low, Position high);

void Swap(Position a, Position b, List* list) 
{ 
    int temp = list->items[a];
    list->items[a] = list->items[b];
    list->items[b] = temp;
}

Position Partition(List* list, Position low, Position high) {
  ListEntry pivot;
  Position i, pivotpos;

  Swap(low, (low + high) / 2, list);

  pivot = list -> items[low];
  pivotpos = low;
  for (i = low + 1; i <= high; i++)
    if (LT(list -> items[i], pivot))
      Swap(++pivotpos, i, list);
  // Move large entry to right, small to left
  Swap(low, pivotpos, list);
  printf("%d \n",pivotpos);
  return pivotpos;
}

void QuickSort(List * list) {
  RecQuickSort(list, 0, list -> count - 1);
}
void RecQuickSort(List * list, Position low, Position high) {
  Position pivotpos;
  //position of the pivot after partitioning 
  if (low < high) {
    pivotpos = Partition(list, low, high);
    RecQuickSort(list, low, pivotpos - 1);
    RecQuickSort(list, pivotpos + 1, high);
  }
}

