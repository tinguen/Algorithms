#include <string>
#include <iostream>
#include <vector>

using namespace std;

#ifndef TREE
#define TREE

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    };
    ~Node() {}
};

class Tree {
private:
    int size;
    Node *root;
public:
    Tree() {
        root = nullptr;
        size = 0;
    }
    ~Tree() {}
    void push(int data);
    int min(int direction = 0);  // direction 0: check the whole tree(default)
    int max(int direction = 0); //            1: left part
                               //             2: right part
    int remove(int value);
    int get_size() {
        return size;
    }
    Node *get_root() {
        return root;
    }
    vector<int> to_array();
    void clear();
};
#endif