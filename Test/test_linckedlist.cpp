#define BOOST_TEST_MODULE LIST_TESTS

#include <utility>
#include<boost/test/included/unit_test.hpp>
#include"../lab3/LinkedList.h"


BOOST_AUTO_TEST_SUITE(list_tests) 


BOOST_AUTO_TEST_CASE(test_size){
    LinkedList<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_front(1);
    list.push_back(4);
    
    BOOST_CHECK_EQUAL(list.size(), 4);
}


BOOST_AUTO_TEST_CASE(l_test_empty) {
    LinkedList<int> list;
    
    BOOST_CHECK_EQUAL(list.size(), 0);
    BOOST_CHECK(list.IsEmpty());
}

BOOST_AUTO_TEST_CASE(l_test_push_back){
    LinkedList<int> list;
    list.push_front(2);
    list.push_back(3);
    list.push_front(1);
    list.push_back(4);

    BOOST_CHECK(list.back() == 4);
}

BOOST_AUTO_TEST_CASE(l_test_push_front){
    LinkedList<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_front(1);
    list.push_back(4);

    BOOST_CHECK(list.front() == 1);
}

BOOST_AUTO_TEST_CASE(l_test_pop_back){
    LinkedList<int> list;
    list.pop_back();
    
    list.push_back(2);
    list.pop_back();
    
    list.push_back(3);
    list.push_front(1);
    list.push_back(4);
    
    list.pop_back();

    BOOST_CHECK(list.back() != 4);
    BOOST_CHECK(list.back() == 3);
}

BOOST_AUTO_TEST_CASE(l_test_pop_front){
    LinkedList<int> list;
    list.pop_front();
    
    list.push_back(2);
    list.push_back(3);
    list.push_front(1);
    list.push_back(4);
    
    list.pop_front();

    BOOST_CHECK(list.front() != 1);
    BOOST_CHECK(list.front() == 2);
}
BOOST_AUTO_TEST_CASE(l_test_find_value){
    LinkedList<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_front(1);
    list.push_back(4);

    auto val = list.find_value(3);
    BOOST_CHECK(val == 3);
}


BOOST_AUTO_TEST_CASE(l_test_remove_value){
    LinkedList<int> list;
    list.remove_value(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(1);
    list.push_back(4);

    list.remove_value(1);
    list.remove_value(4);
    
    list.push_back(5);
    list.remove_value(3);

    auto val1 = list.find_value(3);
    auto val2 = list.find_value(1);
    auto val3 = list.find_value(4);

    BOOST_CHECK(val1 != 3);
    BOOST_CHECK(val2 != 1);
    BOOST_CHECK(val3 != 4);
}

BOOST_AUTO_TEST_SUITE_END()