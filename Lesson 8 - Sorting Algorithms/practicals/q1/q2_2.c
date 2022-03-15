#include <stdio.h>
#include <string.h>

void insertionSort(int size, char arr[][11]);
int binarySearch(char arr[], char key, int count);

int main(){
	int size = 10;
	scanf("%d", &size);

	char a[size][11];
	


	for (int i = 0; i < size; i++) {
      scanf(" %[^\n] ",&a[i]);
   }
    


    insertionSort(size,a);

	for (int i = 0; i < size; i++) {
        //printf("%s\n", a[i]);
    }

	
 
    return 0;
}





void insertionSort(int size, char arr[][11]){
	int c = 0;
	printf("%d\n",c);
	for(int i = 1; i < size; i++){
		c = 0;
		char temp[11];
        strcpy(temp, arr[i]);
		//printf("%s\n",temp);
		int j = i - 1;
		while(j >=0 && (strcmp(arr[j],temp) > 0 || strcmp(arr[j],temp) == 0)){
            strcpy(arr[j+1],arr[j]);
			j--;
			c++;
		}
		printf("%d\n",i-c);
        strcpy(arr[j+1],temp);
	}
}

