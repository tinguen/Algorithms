#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    int student;
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
    void display();
    void fill(int from, int to);
    void remove(int position);
    void clear();
    void moveElements(int L, List *to);
};

