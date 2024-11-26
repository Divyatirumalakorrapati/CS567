#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure with front and rear pointers
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize an empty queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Function to enqueue an element at the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Otherwise, add the new node at the end and move rear to the new node
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue an element from the front of the queue
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;  // Indicates an empty queue
    }

    // Remove the front node and move the front pointer to the next node
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    // If the queue becomes empty, set rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to peek at the front element without removing it
int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to print the elements of the queue (for debugging)
void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    // Enqueue some elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Print the queue
    printf("Queue: ");
    printQueue(&q);

    // Peek at the front element
    printf("Front element: %d\n", peek(&q));

    // Dequeue elements
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    // Print the remaining queue
    printf("Queue after dequeuing: ");
    printQueue(&q);

    return 0;
}
