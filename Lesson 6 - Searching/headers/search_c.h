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

