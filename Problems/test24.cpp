#define BOOST_TEST_MODULE Problems24
#include <boost/test/included/unit_test.hpp>
#include "24.h"

//int main() {
//    ConsistentHashing ch;
//    ch.add("google");
//    ch.add("apple");
//    cout << ch.get_hash("tin.jpg") << endl;
//    cout << ch.get_server("tin.jpg") << endl;
//}

BOOST_AUTO_TEST_CASE(add_check) {
    ConsistentHashing ch;
    ch.add("google");
    ch.add("apple");
    BOOST_TEST(ch.get_size() == 2);
}

BOOST_AUTO_TEST_CASE(remove_check) {
    ConsistentHashing ch;
    ch.add("google");
    ch.add("apple");
    ch.remove("google");
    BOOST_TEST(ch.get_size() == 1);
    ch.remove("not presemt");
    BOOST_TEST(ch.get_size() == 1);
}

BOOST_AUTO_TEST_CASE(get_server_check) {
    long range = 1e9 + 7;
    ConsistentHashing ch;
    ch.add("google");
    ch.add("apple");
    BOOST_TEST(ch.get_server("tin.jpg") == "apple");
    BOOST_TEST(ch.get_server("a") == "google");
}