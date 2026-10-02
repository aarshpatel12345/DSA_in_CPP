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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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

    void reverse_nodes_k_group(int k) {
        if (head == nullptr || k <= 1) return;

        // Dummy node to handle head re-assignment smoothly
        Node dummy(0);
        dummy.next = head;

        Node *group_prev = &dummy;

        while (true) {
            // Check if there are at least k nodes left to reverse
            Node *kth = group_prev;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            // If less than k nodes are left, stop reversing
            if (kth == nullptr) break;

            // Track the start of the next group
            Node *group_next = kth->next;

            // Reverse the current k-group
            Node *prev = group_next;
            Node *current = group_prev->next;

            while (current != group_next) {
                Node *forward = current->next;
                current->next = prev;
                prev = current;
                current = forward;
            }

            // Adjust connections for the outer boundary
            Node *temp = group_prev->next;
            group_prev->next = kth;
            group_prev = temp;
        }

        // Reassign the updated head pointer
        head = dummy.next;
    }
};

int main() {
    LinkedList linked_list;
    linked_list.insert_at_end(1);
    linked_list.insert_at_end(2);
    linked_list.insert_at_end(3);
    linked_list.insert_at_end(4);
    linked_list.insert_at_end(5);

    // Test case 1: k = 2
    // Expected Output: 2 1 4 3 5
    cout << "K = 2: ";
    linked_list.reverse_nodes_k_group(2);
    linked_list.print();



    return 0;
}
