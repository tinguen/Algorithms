#ifndef LAB1_A_LIST_H
#define LAB1_A_LIST_H
#include <string>
#include <iostream>

using namespace std;

class List {
private:
    struct Node {
        int data;
        Node *prev;
        Node *next;
        Node() {
            data = 0;
            prev = nullptr;
            next = nullptr;
        };
        ~Node() {};
    };
    Node *head;
    Node *tail;
    size_t length;
public:
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
            curr = l.tail;
        }
        iterator(const iterator& other):l(other.l),index(other.index)
        {

        }
        void operator++()
        {
            curr = curr->next;
            index++;
        }

        void operator--()
        {
            curr = curr->prev;
            index++;
        }

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
    List();
    ~List();
    string to_string();
    size_t size() {
        return length;
    }
    void insert(int position, int num); // out_of_range exception
    void push(int num);
    int remove(int position); // out_of_range exception
    void fill(int from, int to); // create Nodes with values from 'int from' to 'int to' and push them to the list
    void clear();
    void move_elements(int count, List *dest);
};

#endif //LAB1_A_LIST_H
