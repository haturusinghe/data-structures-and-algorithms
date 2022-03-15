#include <stdio.h>

void merge_sort(int A[], int start, int end);
void merge(int A[], int start, int mid, int end);
int binarySearch(int arr[], int key, int count);

int main() {
    int testCases = 30;
    scanf("%d", & testCases);

    for (int d = 0; d < testCases; d++) {
        int N = 10;
        scanf("%d", & N);
        //printf("test case %d (N = %d):", d,N);

        int weights[N];
        int sorted[N];
        int hold;

        for (int f = 0; f < N; f++) {
            scanf("%d", & hold);
            weights[f] = hold;
            sorted[f] = hold;
        }

        merge_sort(sorted, 0, N-1);

        if (N == 1) {
            printf("0\n");
        } else {
            for (int i = 0; i < N - 1; i++) {
                //printf("%d ", weights[i]);
                int pos = binarySearch(sorted, weights[i], N);
                int mrk = 0;

                if(pos == 0){
                    mrk = 0;
                }else if(pos <= i){
                    mrk = pos;
                }else if(pos > i){
                    mrk = pos - i;
                }
                
                printf("%d ", mrk);

            }
            printf("0\n");
            
        }
    }

    return 0;
}

void merge_sort(int A[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2; // defines the current array in 2 parts .
        merge_sort(A, start, mid); // sort the 1st part of array .
        merge_sort(A, mid + 1, end); // sort the 2nd part of array.

        // merge the both parts by comparing elements of both the parts.
        merge(A, start, mid, end);
    }
}

void merge(int A[], int start, int mid, int end) {
    //stores the starting position of both parts in temporary variables.
    int p = start, q = mid + 1;

    int Arr[end - start + 1], k = 0;

    for (int i = start; i <= end; i++) {
        if (p > mid) //checks if first part comes to an end or not .
            Arr[k++] = A[q++];

        else if (q > end) //checks if second part comes to an end or not
            Arr[k++] = A[p++];

        else if (A[p] < A[q]) //checks which part has smaller element.
            Arr[k++] = A[p++];

        else
            Arr[k++] = A[q++];
    }
    for (int p = 0; p < k; p++) {
        /* Now the real array has elements in sorted manner including both 
             parts.*/
        A[start++] = Arr[p];
    }
}

int binarySearch(int arr[], int key, int count) {
    int top, bottom, middle;
    bottom = 0;
    top = count - 1;
    while (top >= bottom) {
        middle = (top + bottom) / 2;
        if (key == arr[middle]) {
            return middle;
        } else if (key < arr[middle]) {
            top = middle - 1;
        } else {
            bottom = middle + 1;
        }
    }
    return -1;
}