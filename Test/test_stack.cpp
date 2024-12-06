#define BOOST_TEST_MODULE STACK_TESTS

#include<boost/test/included/unit_test.hpp>
#include"../lab3/StackPP.h"


BOOST_AUTO_TEST_SUITE(stack_tests)

BOOST_AUTO_TEST_CASE(s_empty){
    StackPP<int> stack;
    BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
}

BOOST_AUTO_TEST_CASE(q_size){
    StackPP<int> stack;
    BOOST_CHECK_EQUAL(stack.SSize(), 0);
    stack.SPUSH(1);
    stack.SPUSH(2);
    stack.SPUSH(3);
    stack.SPUSH(4);
    BOOST_CHECK_EQUAL(stack.SSize(), 4);
}

BOOST_AUTO_TEST_CASE(s_push){
    StackPP<int> stack;
    stack.SPUSH(1);
    stack.SPUSH(2);
    stack.SPUSH(3);
    BOOST_CHECK_EQUAL(stack.top(), 3);
}

BOOST_AUTO_TEST_CASE(s_pop){
    StackPP<int> stack;
    stack.SPOP();
    stack.SPUSH(1);
    stack.SPUSH(2);
    stack.SPUSH(3);
    stack.SPOP();
    BOOST_CHECK_EQUAL(stack.top(), 2);
}

BOOST_AUTO_TEST_CASE(s_top){
    StackPP<int> stack;
    auto q = stack.top();
    stack.SPUSH(1);
    stack.SPUSH(2);
    stack.SPUSH(3);
    BOOST_CHECK_EQUAL(stack.top(), 3);
}

BOOST_AUTO_TEST_SUITE_END()