#include <iostream>
using namespace std;

#define MAX 100

int a[MAX + 1];
int n = 0;

//Hoan doi hai phan tu
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

//Dua phan tu len tren (Max Heap)
void swim(int a[], int k) {
    while (k > 1 && a[k / 2] < a[k]) {
        swap(a[k], a[k / 2]);
        k = k / 2;
    }
}

//Dua phan tu xuong duoi (Max Heap)
void sink(int a[], int n, int k) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && a[j] < a[j + 1])
            j++;
        if (a[k] >= a[j])
            break;
        swap(a[k], a[j]);
        k = j;
    }
}

//Kiem tra Heap rong
bool isEmpty() {
    return n == 0;
}

//Kiem tra Heap day
bool isFull() {
    return n == MAX;
}

//Chen phan tu
void insert(int x) {
    if (isFull()) {
        cout << "Heap da day!\n";
        return;
    }

    a[++n] = x;
    swim(a, n);

    cout << "Da them " << x << " vao Heap.\n";
}

//Xem phan tu lon nhat
int getMax() {
    if (isEmpty()) {
        cout << "Heap rong!\n";
        return -1;
    }

    return a[1];
}

//Xoa phan tu lon nhat
int delMax() {
    if (isEmpty()) {
        cout << "Heap rong!\n";
        return -1;
    }

    int max = a[1];

    swap(a[1], a[n]);
    n--;

    sink(a, n, 1);

    return max;
}

//In Heap dang mang
void display() {
    if (isEmpty()) {
        cout << "Heap rong!\n";
        return;
    }

    cout << "Heap: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    cout << endl;
}

//In Heap dang cay
void displayTree(int k, int level) {
    if (k > n)
        return;

    displayTree(2 * k + 1, level + 1);

    for (int i = 0; i < level; i++)
        cout << "    ";

    cout << a[k] << endl;

    displayTree(2 * k, level + 1);
}

int main() {
    int choice, x;

    do {
        cout << "\n===== PRIORITY QUEUE - MAX HEAP =====\n";
        cout << "1. Insert (Them phan tu)\n";
        cout << "2. GetMax (Xem phan tu lon nhat)\n";
        cout << "3. DelMax (Xoa phan tu lon nhat)\n";
        cout << "4. Display (In Heap)\n";
        cout << "5. Display Tree (In dang cay)\n";
        cout << "0. Exit\n";

        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri can them: ";
            cin >> x;
            insert(x);
            break;

        case 2:
            if (!isEmpty())
                cout << "Phan tu lon nhat: " << getMax() << endl;
            else
                cout << "Heap rong!\n";
            break;

        case 3:
            if (!isEmpty())
                cout << "Phan tu da xoa: " << delMax() << endl;
            else
                cout << "Heap rong!\n";
            break;

        case 4:
            display();
            break;

        case 5:
            if (!isEmpty())
                displayTree(1, 0);
            else
                cout << "Heap rong!\n";
            break;

        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}