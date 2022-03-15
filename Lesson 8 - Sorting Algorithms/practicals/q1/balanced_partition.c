#include <stdio.h>
void bubbleSort(int size, int arr[][2]);

int main(){
	int t = 100;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
        int n = 2000;
		scanf("%d", &n);
		int a[n][2];
		
		int x,y,h;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d %d %d",&x, &y,&h);
			a[j][0] = (-1 * x) + y;
			a[j][1] = h;
			sum+=h;
		}

		int mid = sum/2;
		for (int k = 0; k < n; k++) {
        	printf("%d %d\n", a[k][0], a[k][1]);
    	}
		printf("mid: %d \n",mid);
    }

    return 0;
}


void bubbleSort(int size, int arr[][2]){
    for(int j = 1; j < size ; j++){
        int flag = 0;

        for(int i = 0; i < size - j; i++){
            if(arr[i][1] > arr[i+1][1]){
                int temp[2] = arr[i];
                arr[i][0] = arr[i+1][0];
                arr[i][1] = arr[i+1][1];
                
                arr[i+1][0] = temp[0];
                arr[i+1][1] = temp[1];
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
