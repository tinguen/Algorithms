void copy_helper(Node *curr_t1, Node *prev_t2) { // prev_t2 - previous Node of tree t2, curr_t1 - current Node of tree t1
    if (curr_t1->left) {
        Node *element = new Node(curr_t1->left->data);
        prev_t2->left = element;
        copy_helper(curr_t1->left, element);
    }
    if (curr_t1->right) {
        Node *element = new Node(curr_t1->right->data);
        prev_t2->right = element;
        copy_helper(curr_t1->right, element);
    }
}

Tree copy(Tree t1, Tree &t2) {
    t2.push(t1.get_root()->data);
    copy_helper(t1.get_root(), t2.get_root());
    return t2;
}
