#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(DFS, EmptyGraph) {
    std::map<int, std::set<int>> adjacency_list;
    Graph g(adjacency_list);
    std::vector<int> expected;
    EXPECT_EQ(g.DFS(0), expected);
}

TEST(DFS, SingleNodeNoEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0};
    EXPECT_EQ(g.DFS(0), expected);
}

TEST(DFS, SingleNodeSingleEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {0}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0};
    EXPECT_EQ(g.DFS(0), expected);
}

TEST(DFS, TwoNodeUnconnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}, {1, {}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0};
    EXPECT_EQ(g.DFS(0), expected);
}

TEST(DFS, TwoNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1}}, {1, {0}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(g.DFS(0), expected);
}

TEST(DFS, MultipleNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 3}}, {1, {0}}, {2, {0, 3}}, {3, {0, 2}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0, 1, 2, 3};
    EXPECT_EQ(g.DFS(0), expected);
}