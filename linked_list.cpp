#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;

    LinkedList() {
        head = nullptr;
    }

    void insert_at_head(int value) {
        Node *temp = new Node(value);
        if (head == nullptr) {
            head = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }

    void insert_at_tail(int value) {
        Node *temp = new Node(value);
        Node *current = head;

        if (head == nullptr) {
            head = temp;
            return;
        }
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }

    void display() const {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linked_list;

    for (int i = 0; i < 5; i++) {
        cout << "Enter value " << i << ": ";
        int value;
        cin >> value;
        // linked_list.insert_at_tail(value);
        linked_list.insert_at_head(value);
    }

    linked_list.display();
    return 0;
}
