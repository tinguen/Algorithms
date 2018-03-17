#include "list.h"

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
}

void List::push(int num) {
    Node *curr = new Node();
    curr->data = num;
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
    s = s + '\n';
    return s;
}

void List::fill(int from, int to) {
    for (int i = from; i <= to; i++) {
        push(i);
    }
}

int List::remove(int position) {
    int size = length;
    if (position > size || position <= 0) {
        throw out_of_range("Invalid position");
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
    int value = curr->data;
    delete curr;
    length--;
    return value;
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

void List::move_elements(int count, List *to) {
    Node *curr = head;
    Node *temp = head;
    // getting the last element to move
    for (int i = 0; i < count - 1; i++) {
        curr = curr->next;
    }
    if (count != length) {
        curr->next->prev = nullptr;
    }
    head = curr->next;
    curr->next = to->head;
    to->head->prev = curr;
    to->head = temp;
    length -= count;
    to->length += count;
}


