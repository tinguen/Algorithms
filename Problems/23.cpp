#include "23.h"

Node *push_helper(Node *root, int value, string data, Node *nil) {
    if (root->key == value) {
        throw invalid_argument("Pushing existing element");
    }
    if (root->key < value) {
        if (root->right == nil) {
            root->right = new Node(value, data);
            root->right->parent = root;
            root->right->left = nil;
            root->right->right = nil;
            return root->right;
        }
        return push_helper(root->right, value, data, nil);
    } else {
        if (root->left == nil) {
            root->left = new Node(value, data);
            root->left->parent = root;
            root->left->left = nil;
            root->left->right = nil;
            return root->left;
        }
        return push_helper(root->left, value, data, nil);
    }
}

Node *RBT::push(int key, string data) {
    if (root != nil) {
        size++;
        return push_helper(root, key, data, nil);
    } else {
        root = new Node(key, data);
        root->parent = nil;
        root->left = nil;
        root->right = nil;
        size++;
        return root;
    }
}

void remove_helper(Node *root, int value, Node *prev, Node *arr[2], Node *nil) { // returns Node with value to remove
    if (root->key == value) {
        arr[0] = prev;
        arr[1] = root;
        return;
    }
    if (root->key < value) {
        if (root->right == nil) {
            return;
        }
        remove_helper(root->right, value, root, arr, nil);
    } else if (root->key > value){
        if (!root->left) {
            return;
        }
        remove_helper(root->left, value, root, arr, nil);
    }
}

Node *tree_successor(Node *x, Node *nil) {
    Node *prev = x;
    Node *tmp = x->left;
    if (tmp->right != nil) {
        return tmp;
    }
    prev = prev->left;
    tmp = tmp->right;
    while (tmp->right != nil) {
        prev = prev->right;
        tmp = tmp->right;
    }
    return tmp;
}

Node *RBT::remove(int value) {
    if (root == nil) {
        return nullptr;
    }
    Node *arr[2] = { nil, nil };
    remove_helper(root, value, nil, arr, nil);
    if (arr[1] == nil) {
        throw out_of_range("No such element to remove");
    }
    Node *y = nullptr;
    Node *z = arr[1];
    Node *x = nullptr;
    if (z->left == nil || z->right == nil) {
        y = z;
    } else {
        y = tree_successor(z, nil);
    }
    if (y->left != nil) {
        x = y->left;
    } else {
        x = y->right;
    }
    x->parent = y->parent;
    if (y->parent == nil) {
        root = x;
    } else {
        if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    }
    if (y == z) {
        z->key = y->key;
    }
    if (!y->color) {
        remove_fixup(x);
    }
    size--;
    return y;
}

void RBT::left_rotate(Node *x) {
    Node *y = x->right;
    if (y == nil) {
        return;
    }
    x->right = y->left;
    if (y->left != nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nil) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBT::right_rotate(Node *y) {
    Node *x = y->left;
    if (x == nil) {
        return;
    }
    y->left = x->right;
    if (x->right != nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nil) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void RBT::insert(int key, string data) {
    Node *x = push(key, data);
    x->color = true;
    while (x != root && x->parent->color) {
        if (x->parent == x->parent->parent->left) {
            Node *y = x->parent->parent->right;
            if (y == nullptr) break;
            if (y->color) {
                x->parent->color = false;
                y->color = false;
                x->parent->parent->color = true;
                x = x->parent->parent;
            } else {
                if (x == x->parent->right) {
                    x = x->parent;
                    left_rotate(x);
                }
                x->parent->color = false;
                x->parent->parent->color = true;
                right_rotate(x->parent->parent);
            }
        } else {
            Node *y = x->parent->parent->left;
            if (y == nullptr) break;
            if (y->color) {
                x->parent->color = false;
                y->color = false;
                x->parent->parent->color = true;
                x = x->parent->parent;
            } else {
                if (x == x->parent->left) {
                    x = x->parent;
                    right_rotate(x);
                }
                x->parent->color = false;
                x->parent->parent->color = true;
                left_rotate(x->parent->parent);
            }
        }
    }
    root->color = false;
}

void RBT::remove_fixup(Node *x) {
    while (x != root && !x->color) {
        if (x == x->parent->left) {
            Node *w = x->parent->right;
            if (w->color) {
                w->color = false;
                x->parent->color = true;
                left_rotate(x->parent);
                w = x->parent->right;
            }
            if (!w->left->color && !w->right->color) {
                w->color = true;
                x = x->parent;
            } else {
                if (!w->right->color) {
                    w->left->color = false;
                    w->color = true;
                    right_rotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = false;
                w->right->color = false;
                left_rotate(x->parent);
                x = root;
            }
        } else {
            Node *w = x->parent->left;
            if (w->color) {
                w->color = false;
                x->parent->color = true;
                right_rotate(x->parent);
                w = x->parent->left;
            }
            if (!w->right->color && !w->left->color) {
                w->color = true;
                x = x->parent;
            } else {
                if (!w->left->color) {
                    w->right->color = false;
                    w->color = true;
                    left_rotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = false;
                w->left->color = false;
                right_rotate(x->parent);
                x = root;
            }
        }
        x->color = false;
    }
}

Node *RBT::search(int key) {
    Node *x = root;
    while (x != nil  && key != x->key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}