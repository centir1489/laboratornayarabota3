#define BOOST_TEST_MODULE QUEUE_TESTS

#include<boost/test/included/unit_test.hpp>
#include"../lab3/QueuePlusPlus.h"


BOOST_AUTO_TEST_SUITE(queue_tests)

BOOST_AUTO_TEST_CASE(q_empty) {
    QueuePP<int> queue;
    BOOST_CHECK_EQUAL(queue.IsEmpty(), true);
}

BOOST_AUTO_TEST_CASE(q_size) {
    QueuePP<int> queue;
    BOOST_CHECK_EQUAL(queue.Size(), 0);
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);
    
    BOOST_CHECK_EQUAL(queue.Size(), 4);
}

BOOST_AUTO_TEST_CASE(q_push) {
    QueuePP<int> queue;
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);

    BOOST_CHECK_EQUAL(queue.Front(), 1);
    BOOST_CHECK_EQUAL(queue.Back(), 3);
}

BOOST_AUTO_TEST_CASE(q_pop) {
    QueuePP<int> queue;
    queue.Pop();
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Pop();
    
    BOOST_CHECK_EQUAL(queue.Front(), 2);
    BOOST_CHECK_EQUAL(queue.Back(), 3);
}

BOOST_AUTO_TEST_CASE(q_front) {
    QueuePP<int> queue;
    auto q = queue.Front();
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);

    BOOST_CHECK_EQUAL(queue.Front(), 1);
}

BOOST_AUTO_TEST_CASE(q_back) {
    QueuePP<int> queue;
    auto q = queue.Back();
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);

    BOOST_CHECK_EQUAL(queue.Back(), 3);
}

BOOST_AUTO_TEST_SUITE_END()