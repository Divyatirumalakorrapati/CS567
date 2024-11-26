#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

// Node structure to represent each element in the queue
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class Queue {
public:
    Queue();  // Constructor to initialize an empty queue
    ~Queue(); // Destructor to free memory

    void enqueue(int data);  // Add an element to the rear of the queue
    int dequeue();           // Remove and return the element at the front of the queue
    bool isEmpty() const;    // Check if the queue is empty
    void display() const;    // Display the elements of the queue
    int front() const;       // Return the front element of the queue

private:
    Node* frontNode; // Pointer to the front node
    Node* rearNode;  // Pointer to the rear node
};

#endif // QUEUE_H
