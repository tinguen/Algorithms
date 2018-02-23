#include "list.h"
#include "test.h"

bool compare(string output, string eoutput) {
    ifstream file1, file2;
    file1.open(output);
    file2.open(eoutput);
    string s1, s2;
    int count = 0;
    while (!file1.eof()) {
        getline(file1, s1);
        getline(file2, s2);
        count++;
        if (s1.compare(s2) != 0) {
            return false;
        }
    }
    remove("output");
    return true;
}

void test() {
    // Test1
    List l1;
    List l2;
    l1.fill(1, 30);
    l2.fill(1, 30);
    l1.moveElements(5, &l2);
    l1.fDisplay(); // output
    l2.fDisplay();
    l1.clear();
    l2.clear();
    if (compare("output", "./Tests/eoutput1")) {
        cout << "Test 1 passed" << endl;
    } else {
        cout << "Test 1 failed" << endl;
    }

    // Test2
    l1.fill(1, 20);
    l1.remove(5);
    l1.insert(5, 100);
    l1.fDisplay();
    l1.clear();
    if (compare("output", "./Tests/eoutput2")) {
        cout << "Test 2 passed" << endl;
    } else {
        cout << "Test 2 failed" << endl;
    }

    // Test3
    l1.fill(1, 25);
    l2.fill(1, 25);
    l1.remove(5);
    l1.insert(5, 100);
    l2.moveElements(10, &l1);
    l1.fDisplay();
    l2.fDisplay();
    if (compare("output", "./Tests/eoutput3")) {
        cout << "Test 3 passed" << endl;
    } else {
        cout << "Test 3 failed" << endl;
    }
}