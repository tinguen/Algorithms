#include "list.h"

Node::Node() {
    student = 0;
    prev = nullptr;
    next = nullptr;
};

Node::~Node() {};

List::List() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

List::~List() {
    clear();
}

Node *List::begin() {
    return head;
}

Node *List::end() {
    return tail;
}

int List::size() {
    return length;
}

int List::insert(int position, int num) {
    int size = length;
    if (position > size || position < 0) {
        throw invalid_argument("Invalid position");
    }
    if (position == size || head == nullptr) {
        push(num);
        return num;
    }
    Node *temp = head;
    Node *curr = new Node();
    curr->student = num;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    curr->prev = temp->prev;
    curr->next = temp;
    if (temp->prev != nullptr) {
        temp->prev->next = curr;
        temp->prev = curr;
    }
    if (position == 0) {
        head = curr;
    }
    length++;
    return num;
}

int List::push(int num) {
    Node *curr = new Node();
    curr->student = num;
    curr->next = nullptr;
    if (head == nullptr) {
        curr->prev = nullptr;
        head = curr;
        tail = curr;;
    } else {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    length++;
    return num;
}

string List::to_string() {
    if (length == 0) {
        return "";
    }
    string s = std::to_string(head->student);
    Node *curr = head->next;
    while (curr != nullptr) {
        s = s + ", " + std::to_string(curr->student);
        curr = curr->next;
    }
    s = s + '\n';
    return s;
}

void List::fill(int from, int to) {
    for (int i = from; i <= to; i++) {
        push(i);
    }
}

void List::remove(int position) {
    int size = length;
    if (position > size || position <= 0) {
        throw invalid_argument("Invalid position");
    }
    Node *curr = head;
    for (int i = 0; i < position - 1; i++) {
        curr = curr->next;
    }
    if (position == 1) {
        head = curr->next;
        curr->next->prev = nullptr;
    }
    if (position == size) {
        tail = curr->prev;
        curr->prev->next = nullptr;
    } else if (position > 1) {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }
    delete curr;
    length--;
}

void List::clear() {
    Node *curr = head;
    Node *temp = nullptr;
    while (curr != nullptr) {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void List::move_elements(int movers, List *to) {
    Node *curr = head;
    Node *temp = head;
    // getting the last element to move
    for (int i = 0; i < movers - 1; i++) {
        curr = curr->next;
    }
    if (movers != length) {
        curr->next->prev = nullptr;
    }
    head = curr->next;
    curr->next = to->head;
    to->head->prev = curr;
    to->head = temp;
    length -= movers;
    to->length += movers;
}


