#include <iostream>
#include "List.cpp"   
using namespace std;

struct Stack {
    List data; 

    bool isEmpty() {
        if (data.size == 0) {
            return true;
        }
        return false;
    }

    void push(int item) {
        data.addLast(item);  
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        int val = data.get(data.size - 1);
        data.removeLast();
        return val;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return data.get(data.size - 1);
    }

    int size() {
        return data.size;
    }
}
