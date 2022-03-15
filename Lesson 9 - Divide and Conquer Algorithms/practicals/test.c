#include "merge_c.h"

int main(int argc, char const *argv[])
{
    int b[] = { 54 ,77,66,85,9,12,17};
    mergeSort(b,0,6);

    for (int i = 0; i < 7; i++)
    {
        printf("%d ",b[i]);
    }
    
    return 0;
}
