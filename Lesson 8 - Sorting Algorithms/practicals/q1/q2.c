#include <stdio.h>

void insertionSort(int size, int arr[]);
int binarySearch(int arr[], int key, int count);

int main(){
	int size = 1000;
	scanf("%d", &size);

	int count = 0;
	char a[size];
	char sorted[size];

	for (int i = 0; i < count; i++)
    {
        char i;
        scanf("%c",&i);
		a[count] = i;
		sorted[count] = i;
		count++;
    }
    
/*
	do {
		char i;
        scanf("%c", &i);
		a[count] = i;
		sorted[count] = i;
		count++;
    } while (getchar() != '\n' && count < size);*/

    //insertionSort(size,sorted);

	for (int i = 0; i < size; i++) {
        printf("%c ", a[i]);
    }

	
 
    return 0;
}


int binarySearch(int arr[], int key, int count){
	int top,bottom,middle;
	bottom = 0;
	top = count - 1;
	while(top >= bottom){
		middle = (top+bottom)/2;
		if(key == arr[middle]){
			return middle;
		}else if(key < arr[middle]){
			top = middle - 1;
		}else{
			bottom = middle + 1;
		}
	}
	return -1;
}


void insertionSort(int size, int arr[]){
	for(int i = 1; i < size; i++){
		int temp = arr[i];
		int j = i - 1;
		while(j >=0 && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

