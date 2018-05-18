#define BOOST_TEST_MODULE Problems1_12
#include <boost/test/included/unit_test.hpp>
#include "1-12.h"

vector<int> test_numbers = {- 7, -5, 1, 2, 3, 4, 5, 6, 7, 8};

BOOST_AUTO_TEST_CASE(problem1_check) {
    Tree_problems t;
    t.manual_push(test_numbers);
    vector<int> expected_s = {5, -5};
    vector<int> expected_d = {- 7, 1, 2, 3, 4, 6, 7, 8};
    BOOST_CHECK(t.problem1_search(5) == expected_s);
    t.problem1_delete(5);
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem2_check) {
    Tree_problems t;
    t.manual_push(test_numbers);
    vector<int> expected_s = {-7, -5, 1, 7, 3, 5};
    vector<int> expected_d = {2, 4, 6, 8};
    BOOST_CHECK(t.problem2_search() == expected_s);
    t.problem2_delete();
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem3_check) {
    Tree_problems t;
    t.manual_push(test_numbers);
    vector<int> expected_s = {8, 7, 6, 2, 3, 4, 5};
    vector<int> expected_d = {- 7, -5, 1};
    BOOST_CHECK(t.problem3_search(1) == expected_s);
    t.problem3_delete(1);
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem4_check) {
    Tree_problems t;
    t.manual_push(test_numbers);
    vector<int> expected_s = {- 7, -5};
    vector<int> expected_d = {1, 2, 3, 4, 5, 6, 7, 8};
    BOOST_CHECK(t.problem4_search(1) == expected_s);
    t.problem4_delete(1);
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem5_check) {
    Tree_problems t;
    t.manual_push(test_numbers);
    vector<int> test_numbers2 = { -7, -5, 1, 5};
    vector<int> expected_s = {- 7, -5, 1, 5};
    vector<int> expected_d = {2, 3, 4, 6, 7, 8};
    BOOST_CHECK(t.problem5_search(test_numbers2) == expected_s);
    t.problem5_delete(test_numbers2);
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem6_check) {
    Tree_problems t;
    t.manual_push(test_numbers);
    vector<int> expected_s = {- 7, -5, 1, 2, 3, 7, 5};
    vector<int> expected_d = {4, 6, 8};
    BOOST_CHECK(t.problem6_search() == expected_s);
    t.problem6_delete();
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem7_check) {
    Tree_problems t;
    t.manual_push(test_numbers);
    vector<int> expected_s = {8, 6, 4};
    vector<int> expected_d = {- 7, -5, 1, 2, 3, 5, 7};
    BOOST_CHECK(t.problem7_search() == expected_s);
    t.problem7_delete();
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem8_check) {
    Tree_problems t;
    t.manual_push(test_numbers);
    vector<int> expected_s = {5, 4, 1, 2, 3};
    vector<int> expected_d = {- 7, -5, 6, 7, 8};
    BOOST_CHECK(t.problem8_search(1, 5) == expected_s);
    t.problem8_delete(1, 5);
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem9_check) {
    Tree_problems t;
    vector<int> test_num = {- 7, -5, 1, 2, 3, 4, 5, 6, 7, 8, 15, 20, 175};
    t.manual_push(test_num);
    vector<int> expected_s = {-7, 175, 8, 7};
    vector<int> expected_d = {-5, 1, 2, 3, 4, 5, 6, 15, 20};
    BOOST_CHECK(t.problem9_search(6) == expected_s);
    t.problem9_delete(6);
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem10_check) {
    Tree_problems t;
    vector<int> test_num = {- 7, -5, 1, 2, 3, 4, 5, 6, 7, 8, 15, 20, 175};
    t.manual_push(test_num);
    vector<int> expected_s = {20, -5, 1, 2, 3, 4, 5};
    vector<int> expected_d = {-7, 6, 7, 8, 15, 175};
    BOOST_CHECK(t.problem10_search(6) == expected_s);
    t.problem10_delete(6);
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem11_check) {
    Tree_problems t;
    vector<int> test_num = {- 7, -5, 1, 2, 3, 4, 5, 6, 7, 8, 15, 20, 175};
    t.manual_push(test_num);
    vector<int> expected_s = {-7, 6, 7, 8, 15};
    vector<int> expected_d = {-5, 1, 2, 3, 4, 5, 20, 175};
    BOOST_CHECK(t.problem11_search(6, 8) == expected_s);
    t.problem11_delete(6, 8);
    BOOST_CHECK(t.to_array() == expected_d);
}

BOOST_AUTO_TEST_CASE(problem12_check) {
    Tree_problems t;
    vector<int> test_num = {- 7, -5, 1, 2, 3, 4, 5, 6, 7, 8, 15, 20, 400};
    t.manual_push(test_num);
    vector<int> expected_s = {400, 4, 1};
    vector<int> expected_d = {-7, -5, 2, 3, 5, 6, 7, 8, 15, 20};
    BOOST_CHECK(t.problem12_search() == expected_s);
    t.problem12_delete();
    BOOST_CHECK(t.to_array() == expected_d);
}