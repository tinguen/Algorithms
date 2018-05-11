#include <string>
#include <iostream>
#include <vector>

using namespace std;

#ifndef graph
#define graph

class Graph {
private:
    vector<vector<int>> graph_matrix;
    void traverse(int index, vector<bool> &);
public:
    Graph(vector<vector<int>>);
    ~Graph() {}
    void add_edge(int, int);
    int add_vertix();
    void remove_edge(int, int);
    void remove_vertix(int);
    vector<int> find_bridges();
    int components(); // returns number of components in the graph
    vector <vector<int>> get_graph() {
        return graph_matrix;
    }
};

#endif