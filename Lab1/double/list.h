//
// Created by Tin on 2/22/18.
//

#ifndef LAB1_A_LIST_H
#define LAB1_A_LIST_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    int student;
    Node *prev;
    Node *next;
};

class List {
public:
    Node *head, *tail;
    int length;

    List();
    ~List();

    Node *insert(int position, int num);
    Node *addNode(int num);
    void remove(int position);
    int size();
    void display();
    void fill(int from, int to);
    void clear();
    void moveElements(int L, List *to);
};

#endif //LAB1_A_LIST_H
