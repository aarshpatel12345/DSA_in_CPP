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

    void print() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
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

    Node *reverse_linkedlist(Node *prev = nullptr, Node *current=nullptr, Node *forward = nullptr) {
        while (current != nullptr) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        return prev;
    }

    void reverse_nodes_k_group(int k) {
        Node temp(0);
        temp.next = head;
        Node *group_prev = &temp;
        Node *group_forward = nullptr;
        Node *current = nullptr;
        int count = 1;
        while (current != nullptr && count <= k) {
            current = current->next;
            count++;
        }
        if (count < k) {
            return;
        }
        group_forward = current->next;
        current = group_prev->next;
        group_prev = reverse_linkedlist(group_prev,current);
    }
};

int main() {
    LinkedList linked_list;
    linked_list.insert_at_end(1);
    linked_list.insert_at_end(2);
    linked_list.insert_at_end(3);
    linked_list.insert_at_end(4);
    linked_list.insert_at_end(5);
    // linked_list.reverse_linkedlist();
    linked_list.reverse_nodes_k_group(3);
    linked_list.print();

    return 0;
}
