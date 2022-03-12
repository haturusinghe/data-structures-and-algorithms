#include "merge.h"

int main(int argc, char const *argv[])
{
    List l;
    createList(&l);
    insertLast(&l, 150);
    insertLast(&l, 369);
    insertLast(&l, 600);
    insertLast(&l, 15);
    insertLast(&l, 5);
    insertLast(&l, 7);
    printList(&l);
    MergeSort(&l);
    printList(&l);
    return 0;
}
