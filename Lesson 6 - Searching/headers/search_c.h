#include <stdio.h>
#include <string.h>

#include "list_c.h"

typedef int KeyType;

#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define GT(a,b) ((a) > (b))

#define EQS(a,b) (!strcmp((a),(b)))
#define LTS(a,b) (strcmp((a),(b)) < 0)

int SequentialSearch(List list,KeyType target){
    for(int i = 0; i < list.count; i++){
     if(EQ(list.items[i],target)){
         return i;
     }   
    }
}

/* RecBinary2: recursive recognizing equality version of binary search.
Pre: The contiguous list list has been created, and bottom and top are indices of
entries in the list.
Post: If an entry in list between bottom and top, inclusive, has key equal to target,
then the function returns the location of one such entry (success). Otherwise,
the function returns - 1 (failure). */
int RecBinary2(List list, ListEntry target, int bottom, int top) {
  int middle = -1;
  if (bottom <= top) {
    middle = (top + bottom) / 2;
    if ((target < list.items[middle])) /* Reduce to the bottom half. */
      middle = RecBinary2(list, target, bottom, middle - 1);
    else if ((target > list.items[middle])) /* Reduce to the top half. */
      middle = RecBinary2(list, target, middle + 1, top);
  }
  return middle;
}

int RecBinary2Search(List list, ListEntry target) {
  return RecBinary2(list, target, 0, listSize(&list)-1);
}

/* Binary2Search: recognizing equality version of binary search.
Pre: The contiguous list list has been created.
Post: If an entry in list has key equal to target, then the function returns the location
of one such entry (success). Otherwise the function returns - 1 (failure). */

int Binary2Search(List list, ListEntry target) {
  int bottom, middle, top;
  top = list.count - 1; /* Initialize bounds to encompass entire list. */
  bottom = 0;
  while (top >= bottom) {
    /* Check terminating condition. */
    middle = (top + bottom) / 2;
    if ((target == list.items[middle]))
      return middle;
    else if ((target < list.items[middle]))
      top = middle - 1; /* Reduce to the bottom half of the list. */
    else
      bottom = middle + 1; /* Reduce to the top half of the list. */
  }
  return -1;
}