#include <iostream>
using namespace std;

const int MAX = 100;

void swapValue(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}


void swim(int a[], int k) {
    while (k > 1 && a[k / 2] < a[k]) {
        swapValue(a[k], a[k / 2]);
        k = k / 2;
    }
}


void sink(int a[], int n, int k) {
    while (2 * k <= n) {
        int j = 2 * k;  

        if (j < n && a[j] < a[j + 1]) {
            j++;
        }

        if (a[k] >= a[j]) {
            break;
        }

        swapValue(a[k], a[j]);
        k = j;
    }
}

void buildHeap(int a[], int n) {
    for (int i = 2; i <= n; i++) {
        swim(a, i);
    }
}

void heapSort(int a[], int n) {
    int size = n;

    while (size > 1) {
        swapValue(a[1], a[size]);

        size--;

        sink(a, size, 1);
    }
}


void display(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}


void displayTree(int a[], int n, int k, int level) {
    if (k > n) {
        return;
    }

    displayTree(a, n, 2 * k + 1, level + 1);

    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
    cout << a[k] << '\n';

    displayTree(a, n, 2 * k, level + 1);
}

int main() {
    int a[MAX + 1];
    int n;

    cout << "Nhap so luong phan tu: ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "So luong khong hop le!\n";
        return 0;
    }

    cout << "Nhap cac phan tu:\n";
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << "\nMang ban dau: ";
    display(a, n);

    // Max Heap.
    buildHeap(a, n);

    cout << "\nMax Heap sau khi xay dung (dang mang):\n";
    display(a, n);

    cout << "Max Heap sau khi xay dung (dang cay):\n";
    displayTree(a, n, 1, 0);

    // Heap Sort tang dan.
    heapSort(a, n);

    cout << "\nMang sau khi Heap Sort (tang dan):\n";
    display(a, n);

    return 0;
}
