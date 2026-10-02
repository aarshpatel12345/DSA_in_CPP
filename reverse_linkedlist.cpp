#include <iostream>
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

    void insert_at_end(int value) {
        Node *temp = new Node(value);
        if (head == nullptr) {
            head = temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void reverse_linked_list() {
        Node *current = head;
        Node *prev = nullptr;
        Node *forward = nullptr;

        if (head == nullptr) {
            return;
        }

        while (current != nullptr) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }

        head = prev;
    }
};

int main() {
    LinkedList linked_list;
    linked_list.insert_at_end(1);
    linked_list.insert_at_end(2);
    linked_list.insert_at_end(3);
    linked_list.insert_at_end(4);
    linked_list.insert_at_end(5);
    linked_list.reverse_linked_list();
    linked_list.display();

    return 0;
}
