<<<<<<< HEAD
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    int get(int i) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < i) {
            temp = temp->next;
            count++;
        }
        if (temp != nullptr) return temp->data;
        return -1;
    } // O(n)


    void addFirst(int x) {
        Node* newNode = new Node{ x, head };
        head = newNode;
    } // O(1)


    void addLast(int x) {
        Node* newNode = new Node{ x, nullptr };
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    } // O(n)


    void insertAt(int x, int pos) {
        if (pos == 0) {
            addFirst(x);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;

        Node* newNode = new Node{ x, temp->next };
        temp->next = newNode;
    } // O(n)


    void deleteFirst() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    } // O(1)


    void deleteLast() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    } // O(n)


    void deleteAt(int pos) {
        if (pos == 0) {
            deleteFirst();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    } // O(n)


    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    } // O(n)


    void traverseReverse(Node* node) {
        if (node == nullptr) return;
        traverseReverse(node->next);
        cout << node->data << " ";
    } 

    void printReverse() {
        traverseReverse(head);
        cout << endl;
    }
}; // O(n)

int main() {
    LinkedList data;

    data.addFirst(9);
    data.addLast(7);
    data.insertAt(15, 1);
    data.deleteAt(0);
    data.traverse();
    data.printReverse();

    return 0;
}

=======
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    int get(int i) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < i) {
            temp = temp->next;
            count++;
        }
        if (temp != nullptr) return temp->data;
        return -1;
    }


    void addFirst(int x) {
        Node* newNode = new Node{ x, head };
        head = newNode;
    }


    void addLast(int x) {
        Node* newNode = new Node{ x, nullptr };
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }


    void insertAt(int x, int pos) {
        if (pos == 0) {
            addFirst(x);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;

        Node* newNode = new Node{ x, temp->next };
        temp->next = newNode;
    }


    void deleteFirst() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }


    void deleteLast() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }


    void deleteAt(int pos) {
        if (pos == 0) {
            deleteFirst();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }


    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void traverseReverse(Node* node) {
        if (node == nullptr) return;
        traverseReverse(node->next);
        cout << node->data << " ";
    }

    void printReverse() {
        traverseReverse(head);
        cout << endl;
    }
};

int main() {
    LinkedList data;

    data.addFirst(9);
    data.addLast(7);
    data.insertAt(15, 1);
    data.deleteAt(0);
    data.traverse();
    data.printReverse();

    return 0;
}

>>>>>>> bd23808ba89561d9b48cbb78660c1e3309d5430c
