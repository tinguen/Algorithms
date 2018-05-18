#define BOOST_TEST_MODULE GRAPH
#include <boost/test/included/unit_test.hpp>
#include "graph.h"

bool is_critical(out_of_range const &er) { return true; }
bool is_critical2(invalid_argument const &er) { return true; }

vector<vector<int>> matrix = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
};

BOOST_AUTO_TEST_CASE(intilization_check) {
    Graph gr(matrix);
    vector<vector<int>> fault_matrix = {
            {0, 1, 1, -1, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 1},
            {0, 0, 0, 1, 0}
    };
    vector<vector<int>> fault_matrix1 = {
            {0, 1, 1, 1, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 1},
    };
    BOOST_TEST(gr.get_graph() == matrix);
    BOOST_CHECK_EXCEPTION(Graph gr1(fault_matrix), invalid_argument, is_critical2);
    BOOST_CHECK_EXCEPTION(Graph gr2(fault_matrix1), invalid_argument, is_critical2);

}

BOOST_AUTO_TEST_CASE(add_edge_check) {
    vector<vector<int>> expected_matrix = {
            {0, 1, 1, 1, 1},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 1},
            {1, 0, 0, 1, 0},
    };
    Graph gr(matrix);
    gr.add_edge(0, 4);
    BOOST_TEST(gr.get_graph() == expected_matrix);
    BOOST_CHECK_EXCEPTION(gr.add_edge(-1, 2), invalid_argument, is_critical2);
    BOOST_CHECK_EXCEPTION(gr.add_edge(1, -1), invalid_argument, is_critical2);
    BOOST_CHECK_EXCEPTION(gr.add_edge(1, 100), invalid_argument, is_critical2);
    BOOST_CHECK_EXCEPTION(gr.add_edge(100, 1), invalid_argument, is_critical2);
}

BOOST_AUTO_TEST_CASE(add_vertix_check) {
    vector<vector<int>> expected_matrix = {
            {0, 1, 1, 1, 0, 0},
            {1, 0, 1, 1, 0, 0},
            {1, 1, 0, 0, 0, 0},
            {1, 1, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0}
    };
    Graph gr(matrix);
    gr.add_vertix();
    BOOST_TEST(gr.get_graph() == expected_matrix);
}

BOOST_AUTO_TEST_CASE(remove_edge_check) {
    vector<vector<int>> expected_matrix = {
            {0, 0, 1, 1, 0},
            {0, 0, 1, 1, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 1},
            {0, 0, 0, 1, 0}
    };
    Graph gr(matrix);
    gr.remove_edge(0 , 1);
    BOOST_TEST(gr.get_graph() == expected_matrix);
    BOOST_CHECK_EXCEPTION(gr.remove_edge(-1, 2), invalid_argument, is_critical2);
    BOOST_CHECK_EXCEPTION(gr.remove_edge(1, -1), invalid_argument, is_critical2);
    BOOST_CHECK_EXCEPTION(gr.remove_edge(1, 100), invalid_argument, is_critical2);
    BOOST_CHECK_EXCEPTION(gr.remove_edge(100, 1), invalid_argument, is_critical2);
    BOOST_CHECK_EXCEPTION(gr.remove_edge(0, 4), out_of_range, is_critical);
}

BOOST_AUTO_TEST_CASE(remove_vertix_check) {
    vector<vector<int>> expected_matrix = {
            {0, 1, 1, 0},
            {1, 0, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
    };
    Graph gr(matrix);
    gr.remove_vertix(3);
    BOOST_TEST(gr.get_graph() == expected_matrix);
    BOOST_CHECK_EXCEPTION(gr.remove_vertix(-1), out_of_range, is_critical);
    BOOST_CHECK_EXCEPTION(gr.remove_vertix(100), out_of_range, is_critical);
}

BOOST_AUTO_TEST_CASE(find_bridge_check) {
    Graph gr(matrix);
    vector<int> bridges = gr.find_bridges();
    for (int i = 0; i < bridges.size(); i++) {
        Graph gr1(matrix);
        int components = gr.components();
        gr1.remove_vertix(bridges[i]);
        BOOST_TEST(gr1.components() - components == 1);
    }
}

BOOST_AUTO_TEST_CASE(components_check) {
    Graph gr(matrix);
    BOOST_TEST(gr.components() == 1);
    gr.add_vertix();
    BOOST_TEST(gr.components() == 2);
}
