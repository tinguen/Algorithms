#include <string>
#include <iostream>


using namespace std;

struct Node {
    int student;
    Node *next;
    Node();
    ~Node();
};

class List {
private:
    Node *head, *tail;
    int length;
public:
    List();
    ~List();

    Node *begin();
    Node *end();
    int size();
    int insert(int position, int num);
    int push(int num);
    string to_string();
    void fill(int from, int to);
    void remove(int position);
    void clear();
    void move_elements(int movers, List *to);
};

