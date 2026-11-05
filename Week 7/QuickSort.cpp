#include <iostream>

using namespace std;

int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pi = partition(arr, first, last);
        quickSort(arr, first, pi - 1);
        quickSort(arr, pi + 1, last);
    }
}