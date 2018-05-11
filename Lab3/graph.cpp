#include "graph.h"

Graph::Graph(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i].size() != matrix.size()) {
            throw invalid_argument("Matrix must be n x n");
        }
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] < 0) {
                throw invalid_argument("Invalid matrix - not a graph");
            }
        }
    }
    graph_matrix = matrix;
}

void Graph::add_edge(int v1, int v2) {
    if (v1 < 0 || v2 < 0 || v1 >= graph_matrix.size() || v2 >= graph_matrix.size()) {
        throw invalid_argument("No such vertix");
    }
    graph_matrix[v1][v2]++;
    if(v1 != v2) graph_matrix[v2][v1]++;
}

int Graph::add_vertix() {
    for (int i = 0; i < graph_matrix.size(); i++) {
        graph_matrix[i].push_back(0);
    }
    vector<int> v1(graph_matrix.size() + 1);
    fill(v1.begin(), v1.end(), 0);
    graph_matrix.push_back(v1);
    return graph_matrix.size() - 1;
}

void Graph::remove_edge(int v1, int v2) {
    if (v1 < 0 || v2 < 0 || v1 >= graph_matrix.size() || v2 >= graph_matrix.size()) {
        throw invalid_argument("No such vertix");
    }
    if (graph_matrix[v1][v2] == 0)
    {
        throw out_of_range("No such edge");
    }
    graph_matrix[v1][v2]--;
    if (v1 != v2) graph_matrix[v2][v1]--;
}

void Graph::remove_vertix(int index) {
    if (index < 0 || index > graph_matrix.size()) {
        throw out_of_range("No such vertix");
    }
    graph_matrix.erase(graph_matrix.begin() + index);
    for (int i = 0; i < graph_matrix.size(); i++) {
        graph_matrix[i].erase(graph_matrix[i].begin() + index);
    }
}

void Graph::traverse(int index, vector<bool> &is_used) {
    is_used[index] = true;
    for (int i = 0; i < graph_matrix.size(); i++) {
        if (graph_matrix[index][i] == 1 && is_used[i] == 0) {
            is_used[i] = true;
            traverse(i, is_used);
        }
    }
}

vector<int> Graph::find_bridges() {
    vector<int> bridges;
    for (int i = 0; i < graph_matrix.size(); i++) {
        Graph copy(graph_matrix);
        int components = copy.components();
        copy.remove_vertix(i);
        if (copy.components() > components) bridges.push_back(i);
    }
    return bridges;
}

int Graph::components() { // returns number of components in the graph
    int components = 1;
    vector<bool> is_used(graph_matrix.size());
    traverse(0, is_used);
    for (int i = 0; i < graph_matrix.size(); i++) {
        if (is_used[i] == 0) {
            components++;
            traverse(i, is_used);
        }
    }
    return components;
}