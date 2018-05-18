#include "1-12.h"

bool is_prime(int number) {
    number = abs(number);
    for (int i = 2; i < number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int sum_of_number(int n) {
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return abs(sum);
}

bool module_sqrt_is_int(float number) {
    number = abs(number);
    number = sqrt(number);
    if (int(number) == number) return true;
    return false;
}

vector<int> Tree_problems::problem1_search(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % n != 0) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem1_delete(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % n == 0) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem2_search() {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem2_delete() {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem3_search(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= n) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem3_delete(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > n) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem4_search(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= n) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem4_delete(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < n) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem5_search(vector<int> elements) {
    vector<int> arr = to_array();
    vector<int> return_arr;
    for (int i = 0; i < elements.size(); i++) {
        if (find(arr.begin(), arr.end(), elements[i]) != arr.end()) {
            return_arr.push_back(elements[i]);
        }
    }
    return return_arr;
}

void Tree_problems::problem5_delete(vector<int> elements) {
    for (int i = 0; i < elements.size(); i++) {
        remove(elements[i]);
    }
}

vector<int> Tree_problems::problem6_search() {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (!is_prime(arr[i])) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem6_delete() {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (is_prime(arr[i])) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem7_search() {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (is_prime(arr[i])) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem7_delete() {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (!is_prime(arr[i])) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem8_search(int from, int to) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (!(arr[i] >= from && arr[i] <= to)) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem8_delete(int from, int to) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= from && arr[i] <= to) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem9_search(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (sum_of_number(arr[i]) <= n) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem9_delete(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (sum_of_number(arr[i]) > n) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem10_search(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (sum_of_number(arr[i]) >= n) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

void Tree_problems::problem10_delete(int n) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (sum_of_number(arr[i]) < n) {
            remove(arr[i]);
        }
    }
}

vector<int> Tree_problems::problem11_search(int from, int to) {
    vector<int> arr = to_array();
    vector<int> arr1;
    for (int i = 0; i < arr.size(); i++) {
        if (sum_of_number(arr[i]) >= from && sum_of_number(arr[i]) <= to) {
            arr1.push_back(arr[i]);
        }
    }
    return arr1;
}

void Tree_problems::problem11_delete(int from, int to) {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (sum_of_number(arr[i]) >= from && sum_of_number(arr[i]) <= to) {
            remove(arr[i]);
        }
    }
}

//template <typename T>
vector<int> Tree_problems::problem12_search() {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (!module_sqrt_is_int(arr[i])) {
            swap(arr[i--], arr.back());
            arr.pop_back();
        }
    }
    return arr;
}

//template <typename T>
void Tree_problems::problem12_delete() {
    vector<int> arr = to_array();
    for (int i = 0; i < arr.size(); i++) {
        if (module_sqrt_is_int(arr[i])) {
            remove(arr[i]);
        }
    }
}

void Tree_problems::random_push(int n) {
    for (int i = 0; i < n; i++) {
        push(rand() % 199 - 99);
    }
}

void Tree_problems::manual_push(vector<int> arr) {
    for (auto it = arr.begin(); it < arr.end(); it++) {
        push(*it);
    }
}
