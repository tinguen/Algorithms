#include "tree.h"

using namespace std;

void copy_helper(Node *curr_t1, Node *prev_t2) { // prev_t2 - previous Node of tree t2, curr_t1 - current Node of tree t1
    if (curr_t1->left) {
        Node *element = new Node(curr_t1->left->data);
        prev_t2->left = element;
        copy_helper(curr_t1->left, element);
    }
    if (curr_t1->right) {
        Node *element = new Node(curr_t1->right->data);
        prev_t2->right = element;
        copy_helper(curr_t1->right, element);
    }
}

Tree copy(Tree t1, Tree &t2) {
    t2.push(t1.get_root()->data);
    copy_helper(t1.get_root(), t2.get_root());
    return t2;
}

int main() {
    Tree t;
    Tree t2;
    t.push(1000);
    t.push(5);
    t.push(7);
    t.push(4);
    t.push(20);
    t.push(15);
    t.push(30);
    t.push(60);
    copy(t, t2);
    vector<int> array = t.to_array();
    vector<int> array2 = t2.to_array();
    for (vector<int>::const_iterator it = array2.begin(); it != array2.end(); it++) {
        cout << *it << endl;
    }
}