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

    void insert_at_position(int position, int value) {
        Node *temp = new Node(value);
        Node *current = head;
        int count = 1;
        while (current != nullptr && count + 1 < position) {
            current = current->next;
            count++;
        }
        temp->next = current->next;
        current->next = temp;
    }

    void delete_from_head() {
        Node *temp = head;
        if (head == nullptr) {
            return;
        }
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void delete_from_tail() {
        Node *current = head;
        if (head == nullptr) {
            return;
        }
        while (current->next->next != nullptr) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = nullptr;
        delete temp;
    }

    void delete_from_position(int position) {
        Node *current = head;
        if (head == nullptr) {
            return;
        }
        int count = 1;
        while (current != nullptr && count + 1 < position) {
            current = current->next;
            count++;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
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
    linked_list.insert_at_tail(1);
    linked_list.insert_at_tail(2);
    linked_list.insert_at_tail(3);
    linked_list.insert_at_tail(4);
    linked_list.insert_at_tail(5);

    linked_list.insert_at_position(4, 40);
    linked_list.delete_from_head();
    linked_list.delete_from_tail();
    linked_list.delete_from_position(2);

    linked_list.display();

    return 0;
}
