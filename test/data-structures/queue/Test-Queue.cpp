#include "gtest/gtest.h"
#include <math.h>
#include <iostream>
#include "../../../src/data-structures/queue/Queue.cpp"

using namespace ds;

TEST(QueueTests, QueueIntCreation) {
    Queue<int> * myQueue = new Queue<int>(3);
    EXPECT_EQ(3, myQueue->get_capacity());
    myQueue->enqueue(4);
    EXPECT_EQ(1, myQueue->get_size());
//    EXPECT_EQ(4, myQueue->dequeue());
//    value = myQueue->peek();
}
