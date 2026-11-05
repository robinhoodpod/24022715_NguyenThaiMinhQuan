#include <iostream>
#include "List.cpp"  
using namespace std;

struct Queue {
    List data; 

    bool isEmpty() {
        if (data.size == 0) {
            return true;
        }
        return false;
    }

    void enqueue(int item) {
        data.addLast(item);   
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }
        int val = data.get(0);   
        data.removeFirst();     
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }
        return data.get(0);
    }

    int size() {
        return data.size;
    }
}



