#include "./list.h"

using namespace std;

List::List() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

List::~List() {
    clear();
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
    // getting the last element before the right position
    for (int i = 0; i < position - 2; i++) {
        temp = temp->next;
    }
    curr->next = temp->next;
    temp->next = curr;
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
        head = curr;
        tail = curr;
    } else {
        tail->next = curr;
        tail = curr;
    }
    length++;
    return curr;
}

void List::display() {
    Node *temp = new Node();
    temp = head;
    while (temp != nullptr) {
        cout << temp->student << endl;
        temp = temp->next;
    }
    cout << endl;
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

    Node *curr = head;

    // getting the last element before the one to remove
    for (int i = 0; i < position - 2; i++) {
        curr = curr->next;
    }

    if (position == 0) {
        head = curr->next;
        delete curr;
        curr = nullptr;
    }

    if (position == size) {
        tail = curr;
        delete curr->next;
        curr->next = nullptr;
    } else if (position > 0) {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    length--;
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

void List::moveElements(int L, List *to) {
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

