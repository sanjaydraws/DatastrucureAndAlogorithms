#include <iostream>
using namespace std;

// Node class representing each element of the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List Class (Insert at head, tail, delete, display)
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor initializes an empty list
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Delete the first node that has the given key
    void deleteNode(int key) {
        if (head == nullptr) return;

        // If the node to delete is the head
        if (head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* curr = head;
        while (curr->next && curr->next->data != key) {
            curr = curr->next;
        }

        // If the node was found, delete it
        if (curr->next) {
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        }
    }

    // Print all elements in the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory of all nodes
    ~SinglyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "Linked List: ";
    list.printList();

    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.printList();

    list.deleteNode(40);
    cout << "After deleting 40: ";
    list.printList();

    return 0;
}
