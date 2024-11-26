#include "Queue.h"
#include <gtest/gtest.h>  // Google Test framework

// Test case for enqueuing and dequeuing elements
TEST(QueueTest, EnqueueDequeue) {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    EXPECT_EQ(q.dequeue(), 10);
    EXPECT_EQ(q.dequeue(), 20);
    EXPECT_EQ(q.dequeue(), 30);
}

// Test case for checking if the queue is empty
TEST(QueueTest, IsEmpty) {
    Queue q;
    EXPECT_TRUE(q.isEmpty());
    q.enqueue(10);
    EXPECT_FALSE(q.isEmpty());
    q.dequeue();
    EXPECT_TRUE(q.isEmpty());
}

// Test case for front element without dequeuing
TEST(QueueTest, FrontElement) {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    EXPECT_EQ(q.front(), 10);
    q.dequeue();
    EXPECT_EQ(q.front(), 20);
}

// Test case for attempting to dequeue from an empty queue
TEST(QueueTest, DequeueEmptyQueue) {
    Queue q;
    EXPECT_THROW(q.dequeue(), std::underflow_error);
}

// Test case for attempting to access the front element of an empty queue
TEST(QueueTest, FrontEmptyQueue) {
    Queue q;
    EXPECT_THROW(q.front(), std::underflow_error);
}

// Test case for displaying queue elements
TEST(QueueTest, DisplayQueue) {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    // You could capture the output or manually check it in the console
    q.display();  // Expected output: 10 20 30
}

