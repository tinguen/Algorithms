#define BOOST_TEST_MODULE Problems
#include <boost/test/included/unit_test.hpp>
#include "13-22.cpp"

using namespace std;

BOOST_AUTO_TEST_CASE(problem_13_check) {
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(100);
    arr.push_back(4);
    vector<int> arr2 = problem_13(arr);
    std::sort(arr.rbegin(), arr.rend());
    BOOST_CHECK(arr == arr2);
}

BOOST_AUTO_TEST_CASE(problem_14_check) {
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(i);
    }
    vector<int> arr_copy(arr);
    problem_14(arr_copy, -1);
    arr.push_back(-1);
    sort(arr.begin(), arr.end());
    BOOST_CHECK(arr == arr_copy);
}

BOOST_AUTO_TEST_CASE(problem_15_check) {
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(i);
    }
    vector<int> arr_copy(arr);
    problem_15(arr_copy);
    sort(arr.rbegin(), arr.rend());
    BOOST_CHECK(arr == arr_copy);
}

BOOST_AUTO_TEST_CASE(problem_16_check) {
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(-100);
    arr.push_back(4);
    vector<int> arr_copy = problem_16(arr);
    arr.erase(remove_if(arr.begin(),
                              arr.end(),
                              [](int x) { return x < 0; }),
               arr.end());
    sort(arr.begin(), arr.end());
    BOOST_CHECK(arr == arr_copy);
}

BOOST_AUTO_TEST_CASE(problem_17_check) {
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(100);
    arr.push_back(4);
    vector<int> arr2 = problem_17(arr);
    sort(arr.begin(), arr.end());
    BOOST_CHECK(arr == arr2);
}

BOOST_AUTO_TEST_CASE(problem_18_check) {
    vector<string> arr;
    arr.push_back("Nguen");
    arr.push_back("Yashjk");
    arr.push_back("Ahbfkbrkw");
    vector<string> expected = { "Ahbfkbrkw", "Nguen", "Yashjk" };
    BOOST_TEST(problem_18(arr) == expected);
}

BOOST_AUTO_TEST_CASE(problem_19_check) {
    vector<pair<double, string>> arr;
    arr.push_back(make_pair(380970482090, "Nguen"));
    arr.push_back(make_pair(380636142251, "Tin"));
    arr.push_back(make_pair(380936112925, "Mom"));
    problem_19(arr);
    bool check = true;
    if (arr[0].first != 380636142251 || arr[1].first != 380936112925 || arr[2].first != 380970482090) check = false;
    BOOST_TEST(check == true);
}

BOOST_AUTO_TEST_CASE(problem_20_check) {
    vector<string> arr;
    arr.push_back("Ahbfkbrkw");
    arr.push_back("Nguen");
    arr.push_back("Yashjk");
    vector<string> expected = { "Nguen", "Yashjk", "Ahbfkbrkw" };
    problem_20(arr);
    BOOST_TEST(arr == expected);
}

BOOST_AUTO_TEST_CASE(problem_21_check) {
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(-100);
    arr.push_back(4);
    vector<int> arr_copy = problem_21(arr);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            arr[i] = abs(arr[i]);
        }
    }
    sort(arr.begin(), arr.end());
    BOOST_TEST(arr == arr_copy);
}

BOOST_AUTO_TEST_CASE(problem_22_check) {
    vector<float> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(i);
    }
    problem_22(arr);
    bool check = true;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) check = false;
    }
    BOOST_TEST(check == true);
}

