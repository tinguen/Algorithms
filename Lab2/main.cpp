#include "tree.h"

using namespace std;

Tree copy(Tree t1, Tree t2) { // make copy of tree t1 into t2
    vector<int> arr = t1.to_array();
    for (auto it = arr.begin(); it != arr.end(); it++) {
        t2.push(*it);
    }
    return t2;
}

int main() {
//    Tree t;
//    Tree t1;
//    t.push(1000);
//    t.push(5);
//    t.push(7);
//    t.push(4);
//    t.push(20);
//    t.push(15);
//    t.push(30);
//    t.push(60);
//    vector<int> array = t.to_array();
//    for (vector<int>::const_iterator it = array.begin(); it != array.end(); it++) {
//        cout << *it << endl;
//    }
//    cout << t.max() << endl;
    Tree t1;
    Tree t2;
    t1.push(50);
    t1.push(10);
    t1.push(80);
    t1.push(100);
    t1.push(60);
    t2 = copy(t1, t2);
    vector<int> array1 = t1.to_array();
    for (vector<int>::const_iterator it = array1.begin(); it != array1.end(); it++) {
        cout << *it << endl;
    }
    vector<int> array2 = t2.to_array();
    for (vector<int>::const_iterator it = array2.begin(); it != array2.end(); it++) {
        cout << *it << endl;
    }
}