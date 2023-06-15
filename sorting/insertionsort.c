#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionsort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
            swap(&arr[j], &arr[j-1]);
        }
    }
}

int main() {
    int n = 5;
    int arr[] = {2, 1, 5, 9, 7};
    insertionsort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
