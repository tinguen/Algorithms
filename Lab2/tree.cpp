#include "tree.h"

void push_helper(Node *root, int value) {
    if (root->data == value) {
        throw invalid_argument("Pushing existing element");
    }
    if (root->data < value) {
        if (!root->right) {
            root->right = new Node(value);
            return;
        }
        push_helper(root->right, value);
    } else {
        if (!root->left) {
            root->left = new Node(value);
            return;
        }
        push_helper(root->left, value);
    }
}

void Tree::push(int data) {
    if (root) {
        push_helper(root, data);
    } else {
        root = new Node(data);
    }
    size++;
}

int min_max_helper(Node *root, bool state) { // bool state: false for min, true for max
    int left; // min or max value in left wing
    int right; // min or max value in right wing

    if (root->left) {
        left = min_max_helper(root->left, state);
    } else if (root->right) {
        if (state) {
            return max(root->data, min_max_helper(root->right, state));
        }
        return min(root->data, min_max_helper(root->right, state));
    } else {
        return root->data;
    }

    if (root->right) {
        right = min_max_helper(root->right, state);
    } else {
        if (state) {
            return max(root->data, left);
        }
        return min(root->data, left);
    }

    if (state) {
        int tmp = max(root->data, left);
        return max(tmp, right);
    }
    int tmp = min(root->data, left);
    return min(tmp, right);
}

int Tree::min(int direction) {
    switch (direction) {
        case 0: {
            return min_max_helper(root, false);
        }
        case 1: {
            if (root->left) {
                return min_max_helper(root->left, false);
            }
            return root->data;
        }
        case 2: {
            if (root->right) {
                return min_max_helper(root->right, false);
            }
            return root->data;
        }
        default:
            throw out_of_range("direction must be in [0, 2]");
    }
}

int Tree::max(int direction) {
    switch (direction) {
        case 0: {
            return min_max_helper(root, true);
        }
        case 1: {
            if (root->left) {
                return min_max_helper(root->left, true);
            }
            return root->data;
        }
        case 2: {
            if (root->right) {
                return min_max_helper(root->right, true);
            }
            return root->data;
        }
        default:
            throw out_of_range("direction must be in [0, 2]");
    }
}

void to_array_helper(Node *root, vector<int> &arr) {
    if (root->data) {
        arr.push_back(root->data);
        if (root->left) {
            to_array_helper(root->left, arr);
        }
        if (root->right) {
            to_array_helper(root->right, arr);
        }
    }
}

vector<int> Tree::to_array() {
    vector<int> arr;
    to_array_helper(root, arr);
    return arr;
};

void clear_helper(Node *root) {
    if (root->left) {
        clear_helper(root->left);
    }
    if (root->right) {
        clear_helper(root->right);
    }
    delete root;
}

void Tree::clear() {
    if (!root) return;
    clear_helper(root);
    root = nullptr;
    size = 0;
}

void remove_helper(Node *root, int value, Node *prev, Node *arr[2]) { // returns Node with value to remove
    if (root->data == value) {
        arr[0] = prev;
        arr[1] = root;
        return;
    }
    if (root->data < value) {
        if (!root->right) {
            return;
        }
        remove_helper(root->right, value, root, arr);
    } else if (root->data > value){
        if (!root->left) {
            return;
        }
        remove_helper(root->left, value, root, arr);
    }
}

int Tree::remove(int value) {
    Node *arr[2] = { nullptr, nullptr };
    remove_helper(root, value, nullptr, arr);
    if (!arr[1]) {
        throw out_of_range("No such element to remove");
    }
    if (!(arr[1])->left && !arr[1]->right) {
        if (arr[0]) {
            if (arr[0]->left == arr[1]) {
                arr[0]->left = nullptr;
            } else {
                arr[0]->right = nullptr;
            }
        }
        delete arr[1];
    } else if (!arr[1]->right) {
        if (arr[0]) {
            if (arr[0]->left == arr[1]) {
                arr[0]->left = arr[1]->left;
            } else {
                arr[0]->right = arr[1]->left;
            }
        }
        delete arr[1];
    } else if (!arr[1]->left) {
        if (arr[0]) {
            if (arr[0]->left == arr[1]) {
                arr[0]->left = arr[1]->right;
            } else {
                arr[0]->right = arr[1]->right;
            }
        }
        delete arr[1];
    } else {
        Node *prev = arr[1];
        Node *tmp = arr[1]->left;
        if (!tmp->right) {
            arr[1]->data = tmp->data;
            arr[1]->left = tmp->right;
            delete tmp;
            if (!arr[0]) {
                root = nullptr;
            }
            size--;
            return value;
        }
        prev = prev->left;
        tmp = tmp->right;
        while (tmp->right) {
            prev = prev->right;
            tmp = tmp->right;
        }
        arr[1]->data = tmp->data;
        prev->right = nullptr;
        delete tmp;
    }
    if (!arr[0]) {
        root = nullptr;
    }
    size--;
    return value;
}

//Tree Tree::copy() {
//    Tree t2;
//    vector<int> arr = to_array();
//    for (auto it = arr.begin(); it != arr.end(); it++) {
//        t2.push(*it);
//    }
//    return t2;
//}

