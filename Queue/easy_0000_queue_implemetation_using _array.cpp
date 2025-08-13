#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size, capacity; // front: index of first element, rear: index of last element
    int* arr; // dynamically allocated array to store queue elements

public:
    // Constructor: Initialize queue with given capacity
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;       // points to front element
        rear = -1;       // rear is initially -1 since queue is empty
        size = 0;        // current number of elements
    }

    // Enqueue: Add element at the rear of the queue
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        // Use circular array logic
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    // Dequeue: Remove element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        // Move front forward (circular logic)
        front = (front + 1) % capacity;
        size--;
    }

    // Peek: Return the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // isEmpty: Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // isFull: Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // getSize: Return number of elements in the queue
    int getSize() {
        return size;
    }

    // Display: Print the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        // Loop from front to rear using circular logic
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }

    // Destructor: Free the dynamically allocated memory
    ~Queue() {
        delete[] arr;
    }
};


int main() {
    Queue q(5); // Create a queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Output: Queue: 10 20 30

    cout << "Front element: " << q.peek() << endl; // Output: 10

    q.dequeue();
    q.display(); // Output: Queue: 20 30

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Queue becomes full here
    q.display(); // Output: Queue: 20 30 40 50 60

    q.enqueue(70); // Should print "Queue is full"

    cout << "Queue size: " << q.getSize() << endl; // Output: 5

    // Remove all elements
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.peek() << endl;
        q.dequeue();
    }

    q.display(); // Output: Queue is empty

    return 0;
}
