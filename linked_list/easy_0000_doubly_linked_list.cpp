#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;       // Holds the value of the node
    Node* prev;     // Points to the previous node in the list
    Node* next;     // Points to the next node in the list

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;  // Points to the first node in the list
    Node* tail;  // Points to the last node in the list

public:
    // Constructor initializes an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a new node at the beginning
    void insertAtHead(int value) {
        Node* newNode = new Node(value);  // Create new node with given value

        // If the list is empty, head and tail both point to the new node
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;     // Link new node to current head
            head->prev = newNode;     // Link current head back to new node
            head = newNode;           // Update head to point to new node
        }
    }

    // Insert a new node at the end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);  // Create new node with given value

        // If the list is empty, head and tail both point to the new node
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;     // Link current tail to new node
            newNode->prev = tail;     // Link new node back to current tail
            tail = newNode;           // Update tail to point to new node
        }
    }

    // Delete the first node that contains the given key
    void deleteNode(int key) {
        if (head == nullptr) return;  // Empty list; nothing to delete

        Node* curr = head;            // Start traversal from head

        // Traverse list to find the node with matching data
        while (curr != nullptr && curr->data != key)
            curr = curr->next;

        if (curr == nullptr) return;  // Node with key not found

        // Case 1: Only one node in the list
        if (curr == head && curr == tail) {
            head = tail = nullptr;
        }
        // Case 2: Node is at the head
        else if (curr == head) {
            head = head->next;
            head->prev = nullptr;
        }
        // Case 3: Node is at the tail
        else if (curr == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // Case 4: Node is in the middle
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;  // Free memory of the deleted node
    }

    // Print list from head to tail
    void printForward() {
        Node* temp = head;  // Start from the beginning
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;  // Move to next node
        }
        cout << "NULL\n";
    }

    // Print list from tail to head
    void printBackward() {
        Node* temp = tail;  // Start from the end
        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;  // Move to previous node
        }
        cout << "NULL\n";
    }

    // Destructor: Free all allocated memory when list is destroyed
    ~DoublyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;  // Delete node to prevent memory leak
        }
    }
};

// Main function to demonstrate list operations
int main() {
    DoublyLinkedList list;

    list.insertAtHead(10);  // List: 10
    list.insertAtHead(20);  // List: 20 <-> 10
    list.insertAtTail(30);  // List: 20 <-> 10 <-> 30
    list.insertAtTail(40);  // List: 20 <-> 10 <-> 30 <-> 40

    list.printForward();    // Print: Forward: 20 <-> 10 <-> 30 <-> 40 <-> NULL
    list.printBackward();   // Print: Backward: 40 <-> 30 <-> 10 <-> 20 <-> NULL

    list.deleteNode(20);    // Delete head
    cout << "After deleting 20:\n";
    list.printForward();    // List: 10 <-> 30 <-> 40

    list.deleteNode(40);    // Delete tail
    cout << "After deleting 40:\n";
    list.printForward();    // List: 10 <-> 30

    return 0;
}
