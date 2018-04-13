#define BOOST_TEST_MODULE Tree
#include <boost/test/included/unit_test.hpp>
#include "tree.h"
#include "copy.cpp"

Tree t1;
Tree t2;

bool is_critical(out_of_range const &er) { return true; }
bool is_critical2(invalid_argument const &er) { return true; }

BOOST_AUTO_TEST_CASE(initialization_check) {
    BOOST_TEST(t1.get_root() == nullptr);
    BOOST_TEST(t1.get_size() == 0);
    t1.clear();
}

BOOST_AUTO_TEST_CASE(push_check) {
    t1.push(5);
    BOOST_TEST(t1.get_root()->data == 5);
    t1.push(10);
    t1.push(1);
    BOOST_TEST(t1.get_root()->left->data == 1);
    BOOST_TEST(t1.get_root()->right->data == 10);
    BOOST_CHECK_EXCEPTION(t1.push(10), invalid_argument, is_critical2);
    t1.clear();
}

BOOST_AUTO_TEST_CASE(min_max_check) {
    t1.push(50);
    BOOST_TEST(t1.min() == 50);
    BOOST_TEST(t1.max() == 50);
    t1.push(10);
    t1.push(20);
    t1.push(80);
    t1.push(100);
    BOOST_TEST(t1.min() == 10);
    BOOST_TEST(t1.max() == 100);
    BOOST_CHECK_EXCEPTION(t1.min(100), out_of_range, is_critical);
    t1.clear();
}

BOOST_AUTO_TEST_CASE(to_array_check) {
    t1.push(50);
    t1.push(10);
    t1.push(20);
    t1.push(80);
    t1.push(100);
    vector<int> arr = { 50, 10, 20, 80, 100 };
    BOOST_TEST(t1.to_array() == arr);
    t1.clear();
}

BOOST_AUTO_TEST_CASE(remove_check) {
    t1.push(50);
    t1.push(10);
    t1.push(80);
    t1.push(100);
    t1.push(60);
    t1.remove(80);
    vector<int> arr1 = { 50, 10, 60, 100 };
    BOOST_TEST(t1.to_array() == arr1);
    t1.remove(100);
    vector<int> arr2 = { 50, 10, 60 };
    BOOST_TEST(t1.to_array() == arr2);
    t1.remove(60);
    vector<int> arr3 = { 50, 10 };
    BOOST_TEST(t1.to_array() == arr3);
    BOOST_CHECK_EXCEPTION(t1.remove(-10000), out_of_range, is_critical);
    t1.clear();
}

BOOST_AUTO_TEST_CASE(copy_check) {
    t1.push(50);
    t1.push(10);
    t1.push(80);
    copy(t1, t2);
    BOOST_TEST(t1.to_array() == t2.to_array());
    t1.clear();
    t2.clear();
}

