
#include <iostream>
using namespace std;

const int Max = 1000;

struct List {
    int arr[Max];
    int size;

    List() {
        size = 0;
    }

    int get(int i) {
        return arr[i];
    } // O(1)

    void addFirst(int x) {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = x;
        size++;
    } // O(n)

    void addLast(int x) {
        arr[size] = x;
        size++;
    } // O(1)

    void insertAt(int x, int i) {
        if (i < 0 || i > size) return;
        for (int j = size; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = x;
        size++;
    } // O(n)

    void removeFirst() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    } // O(n)

    void removeLast() {
        if (size == 0) return;
        size--;
    } // O(1)

    void removeAt(int i) {
        if (i < 0 || i >= size) return;
        for (int j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
    } // O(n)

    void traverse() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } // O(n)

    void traverseReverse() {
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } // O(n)
};

int main() {
    List a;
    a.addFirst(10);      
    a.addLast(20);        
    a.insertAt(15, 1);   
    a.removeAt(0);        
    a.traverse();         
    a.traverseReverse();  

    return 0;
}
=======
#include <iostream>
using namespace std;

const int Max = 1000;

struct List {
    int arr[Max];
    int size;

    List() {
        size = 0;
    }

    int get(int i) {
        return arr[i];
    } // O(1)

    void addFirst(int x) {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = x;
        size++;
    } // O(n)

    void addLast(int x) {
        arr[size] = x;
        size++;
    } // O(1)

    void insertAt(int x, int i) {
        if (i < 0 || i > size) return;
        for (int j = size; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = x;
        size++;
    } // O(n)

    void removeFirst() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    } // O(n)

    void removeLast() {
        if (size == 0) return;
        size--;
    } // O(1)

    void removeAt(int i) {
        if (i < 0 || i >= size) return;
        for (int j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
    } // O(n)

    void traverse() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } // O(n)

    void traverseReverse() {
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } // O(n)
};

int main() {
    List a;
    a.addFirst(10);      
    a.addLast(20);        
    a.insertAt(15, 1);   
    a.removeAt(0);        
    a.traverse();         
    a.traverseReverse();  

    return 0;
}
>>>>>>> bd23808ba89561d9b48cbb78660c1e3309d5430c
