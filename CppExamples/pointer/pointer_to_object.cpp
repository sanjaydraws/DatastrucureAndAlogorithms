

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int main() {
    // Create a Node object dynamically
    Node* ptr = new Node(99);

    cout << "ptr               = " << ptr << endl;               // address of Node object
    cout << "*ptr              = [object, can't print like this]" << endl;
    cout << "(*ptr).data       = " << (*ptr).data << endl;       // access via dereference
    cout << "ptr->data         = " << ptr->data << endl;         // shortcut

    // Clean up
    delete ptr;
    return 0;
}
