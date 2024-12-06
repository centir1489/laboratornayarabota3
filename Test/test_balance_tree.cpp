#define BOOST_TEST_MODULE BALANCE_TREE_TESTS

#include<boost/test/included/unit_test.hpp>
#include"../lab3/AVLTree.h"


BOOST_AUTO_TEST_SUITE(balance_tree_tests)

BOOST_AUTO_TEST_CASE(t_test_1){
    AVLTree tree;
    tree.tinsert(11);
    tree.tinsert(22);
    tree.tinsert(33);
    tree.tinsert(41);
    tree.tinsert(56);
    tree.tinsert(23);

    BOOST_CHECK(tree.tfind(11) == true);
    BOOST_CHECK(tree.tfind(22) == true);
    BOOST_CHECK(tree.tfind(33) == true);
    BOOST_CHECK(tree.tfind(41) == true);
    BOOST_CHECK(tree.tfind(56) == true);
    BOOST_CHECK(tree.tfind(23) == true);
    BOOST_CHECK(tree.tfind(6) == false);
}

BOOST_AUTO_TEST_CASE(t_test_2){
    AVLTree tree;
    tree.tinsert(56);
    tree.tinsert(11);
    tree.tinsert(22);
    tree.tinsert(33);
    tree.tinsert(41);
    tree.tinsert(23);

    tree.tdel(11);
    BOOST_CHECK(tree.tfind(11) == false);

    tree.tdel(22);
    BOOST_CHECK(tree.tfind(22) == false);

    tree.tdel(41);
    BOOST_CHECK(tree.tfind(41) == false);
}

BOOST_AUTO_TEST_CASE(t_test_3){
    AVLTree tree;
    tree.tinsert(10);
    tree.tinsert(20);
    tree.tinsert(30);
    tree.tinsert(40);
    tree.tinsert(50);
    tree.tinsert(25);

    tree.tdel(30);
    BOOST_CHECK(tree.tfind(30) == false);

    tree.tdel(40);
    BOOST_CHECK(tree.tfind(40) == false);

    tree.tdel(20);
    BOOST_CHECK(tree.tfind(20) == false);

    tree.tdel(23);
    BOOST_CHECK(tree.tfind(23) == false);
    
    BOOST_CHECK(tree.getRoot() -> data == 25);
    BOOST_CHECK(tree.getRoot() -> Left -> data == 10);
    BOOST_CHECK(tree.getRoot() -> Right -> data == 50);
}


BOOST_AUTO_TEST_CASE(test_left_rotation) {
    AVLTree tree;

    // правый поворот
    tree.tinsert(10);
    tree.tinsert(20);
    tree.tinsert(30);
    tree.tinsert(11);
    tree.tinsert(12);

    BOOST_CHECK(tree.tfind(20) == true);
    BOOST_CHECK(tree.tfind(10) == true);
    BOOST_CHECK(tree.tfind(30) == true);
    BOOST_CHECK(tree.tfind(11) == true);
    BOOST_CHECK(tree.tfind(12) == true);

    BOOST_CHECK(tree.getRoot() -> data == 20);
    BOOST_CHECK(tree.getRoot() -> Left -> data == 11);
    BOOST_CHECK(tree.getRoot() -> Right -> data == 30);
    BOOST_CHECK(tree.getRoot() -> Left -> Left -> data == 10);
    BOOST_CHECK(tree.getRoot() -> Left -> Right -> data == 12);
}

BOOST_AUTO_TEST_CASE(test_right_rotation) {
    AVLTree tree;

    // левый поворот
    tree.tinsert(10);
    tree.tinsert(20);
    tree.tinsert(30);
    tree.tinsert(25);
    tree.tinsert(28);

    BOOST_CHECK(tree.tfind(10) == true);
    BOOST_CHECK(tree.tfind(20) == true);
    BOOST_CHECK(tree.tfind(30) == true);
    BOOST_CHECK(tree.tfind(25) == true);
    BOOST_CHECK(tree.tfind(28) == true);

    BOOST_CHECK(tree.getRoot() -> data == 20);
    BOOST_CHECK(tree.getRoot() -> Left -> data == 10);
    BOOST_CHECK(tree.getRoot() -> Right -> data == 28);
    BOOST_CHECK(tree.getRoot() -> Right -> Right -> data == 30);
    BOOST_CHECK(tree.getRoot() -> Right -> Left -> data == 25);
}

BOOST_AUTO_TEST_CASE(test_left_right_rotation) {
    AVLTree tree;

    // левый-правый поворот
    tree.tinsert(30);
    tree.tinsert(10);
    tree.tinsert(20);
    tree.tinsert(25);
    tree.tinsert(22);

    BOOST_CHECK(tree.tfind(30) == true);
    BOOST_CHECK(tree.tfind(10) == true);
    BOOST_CHECK(tree.tfind(20) == true);
    BOOST_CHECK(tree.tfind(25) == true);
    BOOST_CHECK(tree.tfind(22) == true);

    BOOST_CHECK(tree.getRoot() -> data == 20);
    BOOST_CHECK(tree.getRoot() -> Left -> data == 10);
    BOOST_CHECK(tree.getRoot() -> Right -> data == 25);
    BOOST_CHECK(tree.getRoot() -> Right -> Right -> data == 30);
    BOOST_CHECK(tree.getRoot() -> Right -> Left -> data == 22);
}

BOOST_AUTO_TEST_CASE(test_right_left_rotation) {
    AVLTree tree;

    //правый-левый поворот
    tree.tinsert(10);
    tree.tinsert(30);
    tree.tinsert(20);
    tree.tinsert(25);
    tree.tinsert(22);

    BOOST_CHECK(tree.tfind(10) == true);
    BOOST_CHECK(tree.tfind(30) == true);
    BOOST_CHECK(tree.tfind(20) == true);
    BOOST_CHECK(tree.tfind(25) == true);
    BOOST_CHECK(tree.tfind(22) == true);

    BOOST_CHECK(tree.getRoot() -> data == 20);
    BOOST_CHECK(tree.getRoot() -> Left -> data == 10);
    BOOST_CHECK(tree.getRoot() -> Right -> data == 25);
    BOOST_CHECK(tree.getRoot() -> Right -> Right -> data == 30);
    BOOST_CHECK(tree.getRoot() -> Right -> Left -> data == 22);
}

BOOST_AUTO_TEST_SUITE_END()