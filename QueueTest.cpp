#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "queue.h"  // Include the queue implementation file

void test_enqueue_dequeue() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Test dequeue
    CU_ASSERT_EQUAL(dequeue(&q), 10);
    CU_ASSERT_EQUAL(dequeue(&q), 20);
    CU_ASSERT_EQUAL(dequeue(&q), 30);
}

void test_isEmpty() {
    Queue q;
    initQueue(&q);
    CU_ASSERT_TRUE(isEmpty(&q));

    enqueue(&q, 10);
    CU_ASSERT_FALSE(isEmpty(&q));

    dequeue(&q);
    CU_ASSERT_TRUE(isEmpty(&q));
}

void test_peek() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    CU_ASSERT_EQUAL(peek(&q), 10);  // Should peek at the front element
}

int main() {
    CU_initialize_registry();
    CU_pSuite pSuite = CU_add_suite("Queue Test Suite", 0, 0);

    // Add test cases
    CU_add_test(pSuite, "Test enqueue and dequeue", test_enqueue_dequeue);
    CU_add_test(pSuite, "Test isEmpty function", test_isEmpty);
    CU_add_test(pSuite, "Test peek function", test_peek);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
