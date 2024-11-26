#include "Queue.h"
#include <stdexcept>

// Constructor: Initializes the queue to be empty
Queue::Queue() : frontNode(nullptr), rearNode(nullptr) {}

// Destructor: Frees all allocated nodes in the queue
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Adds an element to the rear of the queue
void Queue::enqueue(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}

// Removes and returns the front element of the queue
int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty!");
    }

    int frontData = frontNode->data;
    Node* temp = frontNode;
    frontNode = frontNode->next;
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    delete temp;
    return frontData;
}

// Returns true if the queue is empty
bool Queue::isEmpty() const {
    return frontNode == nullptr;
}

// Displays all elements in the queue
void Queue::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }

    Node* current = frontNode;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Returns the front element of the queue without removing it
int Queue::front() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty!");
    }
    return frontNode->data;
}
