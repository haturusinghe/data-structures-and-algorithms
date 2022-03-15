#include <stdio.h>

void selectionSort(int size, int arr[]);
int main(){
	int freq = 50;
	scanf("%d", &freq);

	int farr[freq];
	int q = 0;

	do {
        scanf("%d", &farr[q++]);
    } while (getchar() != '\n' && q < freq);

	int keys = 50;
	scanf("%d", &keys);

	int karr[keys];
	q = 0;

	int numKeys =0;

	do {
        scanf("%d", &karr[q]);
		numKeys += karr[q++];
    } while (getchar() != '\n' && q < keys);

	if(numKeys < freq){
		printf("-1");
	}else{

	selectionSort(freq, farr);
	selectionSort(keys, karr);

	int t = 1;
    int kpt = 0;
	int fpt = freq-1;
	int count = 0;
	int sum = 0;

	while( fpt >= 0 ){
		
		if(t <= karr[kpt]){
			//printf("%d x %d\n",farr[fpt],t);
			sum += farr[fpt]*t;
			kpt++;
		}else{
			kpt++;
			continue;
		}

		if(kpt >= keys){
			kpt = 0;
			t++;

		}
		fpt--;
	}
	printf("%d",sum);

	}

	
	
	

	/*for (int i = freq - 1; i >= 0; i--) {
		int t = 1;
		for(int h = 0; h < keys)

		sum += farr[i] * t;
	}/*
	printf("\n");
	for (int i = 0; i < keys; i++) {
		printf("%d ",karr[i]);
	}*/


    return 0;
}


void selectionSort(int size, int arr[]){
	int smallest, i, j;
	for( i=0; i < size; i++){
		smallest = i;
		for( j = i+1; j < size ; j++){
			if(arr[j] < arr[smallest]){
				smallest = j;
			}
		}
		int temp = arr[smallest];
		arr[smallest] = arr[i];
		arr[i] = temp;
	}
}


