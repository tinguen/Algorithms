#define BOOST_TEST_MODULE LinkedList
#include <boost/test/included/unit_test.hpp>
#include "../list.h"

List l1;
List l2;

bool is_critical(out_of_range const &er) { return true; }

BOOST_AUTO_TEST_CASE(initialization_check) {
    BOOST_TEST(l1.size() == 0);
    l1.clear();
}

BOOST_AUTO_TEST_CASE(push_check) {
    l1.push(5);
    BOOST_TEST(l1.to_string().compare("5\n") == 0);
    l1.clear();
}

BOOST_AUTO_TEST_CASE(insert__and_to_string_check) {
    l1.insert(0, 5);
    BOOST_TEST(l1.to_string().compare("5\n") == 0);
    BOOST_CHECK_EXCEPTION(l1.insert(5, -100), out_of_range, is_critical);
    BOOST_CHECK_EXCEPTION(l1.insert(5, 100), out_of_range, is_critical);
    l1.insert(1, 100);
    BOOST_TEST(l1.to_string().compare("5, 100\n") == 0);
    l1.insert(0, 10);
    BOOST_TEST(l1.to_string().compare("10, 5, 100\n") == 0);
    l1.clear();
}

BOOST_AUTO_TEST_CASE(fill_check) {
    l1.fill(1, 5);
    BOOST_TEST_CHECK(l1.to_string().compare("1, 2, 3, 4, 5\n") == 0);
    l1.clear();
}

BOOST_AUTO_TEST_CASE(remove_check)  {
    l1.fill(1, 5);
    BOOST_CHECK_EXCEPTION(l1.remove(100), out_of_range, is_critical);
    BOOST_CHECK_EXCEPTION(l1.remove(-5), out_of_range, is_critical);
    l1.remove(5);
    BOOST_TEST(l1.to_string().compare("1, 2, 3, 4\n") == 0);
    l1.remove(1);
    BOOST_TEST(l1.to_string().compare("2, 3, 4\n") == 0);
    l1.clear();
}

BOOST_AUTO_TEST_CASE(move_elements_check) {
    l1.fill(1, 5);
    l2.fill(6, 10);
    l1.move_elements(5, &l2);
    BOOST_TEST(l1.to_string().compare("") == 0);
    BOOST_TEST(l2.to_string().compare("1, 2, 3, 4, 5, 6, 7, 8, 9, 10\n") == 0);
}
