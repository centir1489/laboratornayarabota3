#define BOOST_TEST_MODULE MASSIV_TESTS

#include<boost/test/included/unit_test.hpp>
#include"../lab3/Massiv.h"

BOOST_AUTO_TEST_CASE(m_init_capacity){
    Massiv<int> mass(22);

    BOOST_CHECK_EQUAL(mass.Capacity, 22);
}

BOOST_AUTO_TEST_CASE(m_length){
    Massiv<int> mass = {1, 2, 3, 4, 5};

    BOOST_CHECK_EQUAL(mass.MLength(), 5);
}

BOOST_AUTO_TEST_CASE(m_resize){
    Massiv<int> mass(2);
    mass.Resize(16);
    BOOST_CHECK(mass.Capacity == 16);
}



BOOST_AUTO_TEST_CASE(m_oper_2){ // []
    Massiv<int> mass = {1, 2, 3, 4, 5};
    int Data[5] = {1, 2, 3, 4, 5};
    bool oper = true;
    for(size_t q = 0; q < 5; q++){
        if(Data[q] != mass[q]){
            oper = false;
            break;
        }
    }
    BOOST_CHECK(oper == true);
}

BOOST_AUTO_TEST_CASE(m_push_back){
    Massiv<int> mass = {1, 2, 3, 4, 5};
    mass.MPUSH(6);
    BOOST_CHECK(mass[5] == 6);
}

BOOST_AUTO_TEST_CASE(m_push_index){
    Massiv<int> mass = {1, 2, 3, 4, 5};
    mass.MPushIndex(2, 11);
    BOOST_CHECK(mass[2] == 11);
}

BOOST_AUTO_TEST_CASE(m_pop_index){
    Massiv<int> mass = {1, 2, 3, 4, 5};
    mass.MPOP(2);
    BOOST_CHECK(mass[2] != 3);
    BOOST_CHECK(mass[2] == 4);
}