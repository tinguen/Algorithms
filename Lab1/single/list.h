#include <string>
#include <iostream>


using namespace std;

struct Node {
    int data;
    Node *next;
    Node();
    ~Node();
};

class List {
private:
    Node *head, *tail;
    size_t length;
public:
    List();
    ~List();
    class iterator
    {
    private:
        const List &l;
        Node *curr;
        size_t index;
    public:
        iterator(const List &s): l(s), index(0)
        {
            curr = l.head;
        }
        iterator(const List &s, size_t nSize): l(s),index(nSize)
        {

        }
        iterator(const iterator& other):l(other.l),index(other.index)
        {

        }
        void operator++()
        {
            curr = curr->next;
            index++;
        }

//        void operator--()
//        {
//            curr = curr->pr;
//            index++;
//        }

        bool operator != (const iterator& other)
        {
            return index != other.index;
        }

        int operator *()
        {
            if (curr) {
                return curr->data;
            }
            return -1;
        }
    };
    iterator begin()
    {
        iterator it(*this);
        return it;
    }
    iterator end()
    {
        iterator it(*this, size());
        return it;
    }
    size_t size() {
        return length;
    };
    void insert(int position, int num);
    void push(int num);
    string to_string();
    void fill(int from, int to); // create Nodes with values from 'int from' to 'int to' and push them to the list
    int remove(int position);
    void clear();
    void move_elements(int count, List *to);
};

