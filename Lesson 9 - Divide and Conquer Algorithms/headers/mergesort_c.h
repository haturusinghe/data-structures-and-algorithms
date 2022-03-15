#include <stdio.h>
#include <stdlib.h>

void merge(int* arr,int start, int end);

void mergeSort(int* arr, int start, int end){

    if(start >= end){
        return;
    }else{
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, end);
    }
    
}

void merge(int* a, int start, int end){
    
    int i = start;
    int mid = (start + end) / 2;
    int j = mid + 1;

    int k = 0;
    int temp[end - start + 1];

    while(i <= mid && j <= end){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }

    while(i <= mid){
        temp[k++] = a[i++];
    }

    while(j <= end){
        temp[k++] = a[j++];
    }

    for(int p = 0; p < k; p++){
        a[start + p] = temp[p];
    }

}