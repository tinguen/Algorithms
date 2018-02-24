#ifndef LAB1_A_LIST_H
#define LAB1_A_LIST_H
#include <string>
#include <iostream>

using namespace std;

struct Node {
    int student;
    Node *prev;
    Node *next;
    Node();
    ~Node();
};

class List {
private:
    Node *head;
    Node *tail;
    int length;
public:
    List();
    ~List();
    string to_string();
    Node *begin();
    Node *end();
    int size();
    int insert(int position, int num);
    int push(int num);
    void remove(int position);
    void fill(int from, int to);
    void clear();
    void move_elements(int L, List *to);
};

#endif //LAB1_A_LIST_H
