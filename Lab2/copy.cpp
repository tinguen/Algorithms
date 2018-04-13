Tree copy(Tree t1, Tree t2) { // make copy of tree t1 into t2
    vector<int> arr = t1.to_array();
    for (auto it = arr.begin(); it != arr.end(); it++) {
        t2.push(*it);
    }
    return t2;
}