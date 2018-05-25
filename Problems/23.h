#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int key;
    string data;
    Node *parent;
    Node *left;
    Node *right;
    bool color; // false - black, true - red
    Node(int k, string dt) {
        key = k;
        data = dt;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        color = false;
    }
    ~Node() {}
};

class RBT {
private:
    int size = 0;
    Node *push(int, string);
    Node *nil = new Node(0, "");
    Node *root = nil;
public:
    Node *remove(int key);
    void left_rotate(Node *x);
    void right_rotate(Node *y);
    void insert(int key, string data);
    void remove_fixup(Node *x);
    Node *search(int key);
    Node *get_root() {
        return root;
    }
    Node *get_nil() {
        return nil;
    }
    bool get_color(int key) {
        return search(key)->color;
    }
 };

class HashTable {
private:
    RBT arr[1000];
public:
    int hash(int key) {
        return key % 1000;
    }
    void push(int key, string data) {
        int index = hash(key);
        arr[index].insert(key, data);
    }
    Node *search(int key) {
        int index = hash(key);
        return arr[index].search(key);
    }
    Node *remove(int key) {
        int index = hash(key);
        return arr[index].remove(key);
    }
    RBT get_tree(int index) {
        int i = hash(index);
        return arr[i];
    }
};
