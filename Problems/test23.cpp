#define BOOST_TEST_MODULE Problems23
#include <boost/test/included/unit_test.hpp>
#include "23.h"

bool is_critical(out_of_range const &er) { return true; }
bool is_critical2(invalid_argument const &er) { return true; }

BOOST_AUTO_TEST_CASE(rbt_initialization_check) {
    RBT t1;
    BOOST_TEST(t1.get_root() == t1.get_nil());
}

BOOST_AUTO_TEST_CASE(rbt_insert_check) {
    RBT t1;
    t1.insert(5, "a");
    BOOST_TEST(t1.get_root()->key == 5);
    t1.insert(10, "b");
    t1.insert(1, "c");
    BOOST_TEST(t1.get_root()->left->key == 1);
    BOOST_TEST(t1.get_root()->right->key == 10);
    BOOST_CHECK_EXCEPTION(t1.insert(10, "d"), invalid_argument, is_critical2);
}

BOOST_AUTO_TEST_CASE(rbt_insert_red_uncle) {
    RBT t1;
    t1.insert(5, "a");
    t1.insert(10, "b");
    t1.insert(1, "c");
    t1.insert(9, "d");
    BOOST_TEST(t1.get_color(9));
    BOOST_TEST(!t1.get_color(10));
    BOOST_TEST(!t1.get_color(1));
    BOOST_TEST(!t1.get_color(5));
}

BOOST_AUTO_TEST_CASE(rbt_insert_black_uncle_left) {
    RBT t1;
    t1.insert(5, "a");
    t1.insert(10, "b");
    t1.insert(1, "c");
    t1.insert(9, "d");
    t1.insert(8, "e");
    BOOST_TEST(!t1.get_color(9));
    BOOST_TEST(t1.get_color(10));
    BOOST_TEST(!t1.get_color(1));
    BOOST_TEST(!t1.get_color(5));
    BOOST_TEST(t1.get_color(8));
}

BOOST_AUTO_TEST_CASE(rbt_insert_black_uncle_right) {
    RBT t1;
    t1.insert(5, "a");
    t1.insert(10, "b");
    t1.insert(1, "c");
    t1.insert(8, "d");
    t1.insert(9, "e");
    BOOST_TEST(!t1.get_color(9));
    BOOST_TEST(t1.get_color(10));
    BOOST_TEST(!t1.get_color(1));
    BOOST_TEST(!t1.get_color(5));
    BOOST_TEST(t1.get_color(8));
}

BOOST_AUTO_TEST_CASE(remove_check) {
    RBT t1;
    t1.insert(5, "a");
    t1.insert(10, "b");
    t1.remove(10);
    BOOST_TEST(t1.search(10) == t1.get_nil());
}

BOOST_AUTO_TEST_CASE(rbt_search_check) {
    RBT t1;
    t1.insert(5, "a");
    t1.insert(10, "b");
    t1.insert(1, "c");
    BOOST_TEST(t1.search(5)->data == "a");
    BOOST_TEST(t1.search(100) == t1.get_nil());
}

BOOST_AUTO_TEST_CASE(ht_push_check) {
    HashTable ht;
    ht.push(5, "a");
    ht.push(1005, "b");
    RBT tree = ht.get_tree(ht.hash(5));
    BOOST_TEST(tree.search(5)->data == "a");
    BOOST_TEST(tree.search(1005)->data == "b");
}

BOOST_AUTO_TEST_CASE(ht_search_check) {
    HashTable ht;
    ht.push(5, "a");
    RBT tree = ht.get_tree(ht.hash(5));
    BOOST_TEST(ht.search(5)->data == "a");
}

BOOST_AUTO_TEST_CASE(ht_remove_check) {
    HashTable ht;
    ht.push(5, "a");
    ht.push(1005, "b");
    ht.remove(5);
    RBT tree = ht.get_tree(ht.hash(5));
    BOOST_TEST(tree.search(5) == tree.get_nil());
    BOOST_TEST(tree.search(1005)->data == "b");
}

