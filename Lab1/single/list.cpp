#include "list.h"

using namespace std;

Node::Node() {
    data = 0;
    next = nullptr;
}

Node::~Node() {}

List::List() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

List::~List() {
    clear();
}

void List::insert(int position, int num) {
    int size = length;
    if (position > size || position < 0) {
        throw out_of_range("Invalid position");
    }
    if (position == size || head == nullptr) {
        push(num);
        return;
    }
    Node *temp = head;
    Node *curr = new Node();
    curr->data = num;
    if (position == 0) {
        curr->next = temp;
        head = curr;
        length++;
        return;
    }
    // getting the last element before the right position
    for (int i = 0; i < position - 2; i++) {
        temp = temp->next;
    }
    curr->next = temp->next;
    temp->next = curr;
    length++;
    return;
}

void List::push(int num) {
    Node *curr = new Node();
    curr->data = num;
    curr->next = nullptr;
    if (head == nullptr) {
        head = curr;
        tail = curr;
    } else {
        tail->next = curr;
        tail = curr;
    }
    length++;
}

string List::to_string() {
    if (length == 0) {
        return "";
    }
    string s = std::to_string(head->data);
    Node *curr = head->next;
    while (curr != nullptr) {
        s += ", " + std::to_string(curr->data);
        curr = curr->next;
    }
    s += '\n';
    return s;
}

void List::fill(int from, int to) {
    for (int i = from; i <= to; i++) {
        push(i);
    }
}

int List::remove(int position) {
    int size = length;
    int value;
    if (position > size || position <= 0) {
        throw out_of_range("Invalid position");
    }
    Node *curr = head;
    // getting the last element before the one to remove
    for (int i = 0; i < position - 2; i++) {
        curr = curr->next;
    }
    if (position == 1) {
        head = curr->next;
        value = curr->data;
        delete curr;
    }
    if (position == size) {
        tail = curr;
        value = curr->next->data;
        delete curr->next;
        curr->next = nullptr;
    } else if (position > 1) {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        value = temp->data;
        delete temp;
    }
    length--;
    return value;
}

void List::clear() {
    Node *temp = nullptr;
    Node *curr = head;
    while (curr != nullptr) {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void List::move_elements(int L, List *to) {
    Node *curr = head;
    Node *temp = head;
    // getting the last element to move
    for (int i = 0; i < L - 1; i++) {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = to->head;
    to->head = temp;
    length -= L;
    to->length += L;
};

