#include "list_c.h"
/* HeapSort: sort contiguous list by the heap sort method.
Pre: The contiguous list list has been created. Each entry of list contains a key.
Post: The entries of list have been rearranged so that the keys in all the entries are
sorted into nondecreasing order.
Uses: BuildFleap, InsertHeap. */
void HeapSort(List * list) {
  Position lu; /* Entries beyond lu have been sorted. */
  ListEntry current; /* holds entry temporarily removed from list */
  BuildHeap(list); /* First phase: turn list into a heap. */
  for (lu = list->count - 1; lu >= 1; lu--) {
    current = list -> items[lu]; /* Extract last element from list. */
    list -> items[lu] = list -> items[0]; /* Move top of heap to end of list. */
    InsertHeap(current, 0, lu - 1, list);
  }
}

/* InsertHeap: insert an entry into the heap.
Pre: The entries of contiguous list list between indices low + 1 and high, inclusive,
form a heap. The entry in position low will be discarded.
Post: The entry current has been inserted into list and the entries rearranged so that
the entries between indices low and high, inclusive, form a heap. */
void InsertHeap(ListEntry current, Position low, Position high, List * list) {
  Position large; /* position of child of list->entry [low] with the larger key */
  large = 2 * low + 1; /* large is now the left child of low. */
  while (large <= high) {
    if (large < high && LT(list -> items[large], list -> items[large + 1]))
      large++; /* large is now the child of low with the largest key. */
    if (GE(current, list -> items[large]))
      break;
    else {
      /* Promote entry [large] and move down the tree. */
      list -> items[low] = list -> items[large];
      low = large;
      large = 2 * low + 1;
    }
  }
  list -> items[low] = current;
}

/* BuildHeap: build a heap from a random contiguous list.
Pre: The contiguous list list has been created. Each entry of list contains a key.
Post: The entries of list have been rearranged so that list becomes a heap.
Uses: InsertHeap. */
void BuildHeap(List * list) {
  Position low; /* Entries beyond low form a heap. */
  for (low = list -> count / 2 - 1; low >= 0; low--)
    InsertHeap(list -> items[low], low, list -> count, list);
}