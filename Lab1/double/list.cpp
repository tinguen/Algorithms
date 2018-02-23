#include "list.h"

List::List() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

List::~List() {
    clear();
    std::remove("output");
}

Node *List::insert(int position, int num) {
    Node *temp = head;
    Node *curr = new Node();
    curr->student = num;
    int size = length;
    if (position > size || position < 0) {
        throw invalid_argument("Invalid position");
    }
    curr->student = num;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    curr->prev = temp->prev;
    curr->next = temp;
    temp->prev->next = curr;
    temp->prev = curr;
    if (position == 0) {
        head = curr;
    }
    if (position == size) {
        tail = curr;
    }
    length++;
    return curr;
}

Node *List::addNode(int num) {
    Node *curr = new Node();
    curr->student = num;
    curr->next = nullptr;
    if (head == nullptr) {
        curr->prev = nullptr;
        head = curr;
        tail = curr;
        length++;
        return curr;
    }
    tail->next = curr;
    curr->prev = tail;
    tail = curr;
    length++;
    return curr;
}

void List::display() {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->student << endl;
        curr = curr->next;
    }
    cout << endl;
}

void List::fDisplay() {
    ofstream file;
    file.open("output", ios_base::app);
    if (!file) {
        file.open("output");
    }
    Node *temp = head;
    while (temp != nullptr) {
        file << temp->student << endl;
        temp = temp->next;
    }
    file << endl;
    file.close();
}

void List::fill(int from, int to) {
    for (int i = from; i <= to; i++) {
        addNode(i);
    }
}

void List::remove(int position) {
    int size = length;
    if (position > size || position < 0) {
        throw invalid_argument("Invalid position");
    }
    Node *temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    if (position == 0) {
        head = temp->next;
        temp->next->prev = nullptr;
        delete temp;
        temp = nullptr;
    }
    if (position == size) {
        tail = temp->prev;
        temp->prev->next = nullptr;
        delete temp;
    } else if (position > 0) {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
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

void List::moveElements(int L, List *to) {
    Node *curr = head;
    Node *temp = head;
    // getting the last element to move
    for (int i = 0; i < L - 1; i++) {
        curr = curr->next;
    }
    curr->next->prev = nullptr;
    head = curr->next;
    curr->next = to->head;
    to->head->prev = curr;
    to->head = temp;
    length -= L;
    to->length += L;
}


