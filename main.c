#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyon Prototipleri
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
    int i, N;
    printf("HEAP SORT ALGORITMASI\n");
    printf("Kac adet sayi uretilecek: ");
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    srand(time(0));
    printf("Dizi Elemanlari: ");
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    heapSort(arr, N);
    printf("\nSiralanmis Dizi Elemanlari: ");
    printArray(arr, N);
    free(arr);
    return 0;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
