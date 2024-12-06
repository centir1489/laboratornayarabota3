#define BOOST_TEST_MODULE HASH_TABLES_TESTS

#include<boost/test/included/unit_test.hpp>
#include"../lab3/HashTable.h"


BOOST_AUTO_TEST_SUITE(hash_table_tests)

BOOST_AUTO_TEST_CASE(h_construct_1){
    HashTable ht;
    
    BOOST_CHECK_EQUAL(ht.Capacity, 16);
    BOOST_CHECK_EQUAL(ht.Size, 0);
}

BOOST_AUTO_TEST_CASE(h_construct_2){
    HashTable ht(5);
    
    BOOST_CHECK_EQUAL(ht.Capacity, 5);
    BOOST_CHECK_EQUAL(ht.Size, 0);
}

BOOST_AUTO_TEST_CASE(test_HashTable_empty){
    HashTable ht;

    //  таблица пуста
    BOOST_CHECK_EQUAL(ht.HSize(), 0);
    BOOST_CHECK_EQUAL(ht.HFIND("nonexistent_key"), "");
}

BOOST_AUTO_TEST_CASE(h_Capacity){
    HashTable ht(5);
    ht.HPUSH("ABC324", "ABC324");
    ht.HPUSH("AB320", "AB320");
    ht.HPUSH("Linux", "ABc");
    ht.HPUSH("Windows", "ABc");
    ht.HPUSH("AB321", "AD321");
    ht.HPUSH("ABC324", "ABc324");
    ht.HPUSH("problem", "problem");
    BOOST_CHECK_EQUAL(ht.Capacity, 5);
    BOOST_CHECK_EQUAL(ht.Size, 5);
}

BOOST_AUTO_TEST_CASE(h_delete){
    HashTable ht(5);
    ht.HPUSH("ABC324", "ABC324");
    ht.HPUSH("AB320", "AB320");
    ht.HPUSH("Linux", "ABc");
    ht.HPUSH("Windows", "ABc");
    ht.HPUSH("AB321", "AD321");
    ht.HPUSH("ABC324", "ABc324");
    ht.HDEL("Linux");
    ht.HDEL("AB321");
    ht.HDEL("Windows");
    ht.HDEL("Ubuntu");
    BOOST_CHECK_EQUAL(ht.Capacity, 5);
    BOOST_CHECK_EQUAL(ht.HSize(), 3);
}

BOOST_AUTO_TEST_CASE(h_find){
    HashTable ht(5);
    ht.HPUSH("ABC324", "ABC324");
    ht.HPUSH("AB320", "AB320");
    ht.HPUSH("Linux", "ABc");
    ht.HPUSH("Windows", "ABc");
    ht.HPUSH("AB321", "AD321");
    ht.HPUSH("ABC324", "ABc324");
    ht.HDEL("Linux");
    BOOST_CHECK_EQUAL(ht.Capacity, 5);
    BOOST_CHECK_EQUAL(ht.HSize(), 4);
}

BOOST_AUTO_TEST_SUITE_END()