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

//-----------------------------------------------------------------------------

TEST(DFSAll, EmptyGraph) {
    std::map<int, std::set<int>> adjacency_list;
    Graph g(adjacency_list);
    std::vector<int> expected;
    EXPECT_EQ(g.DFSAll(), expected);
}

TEST(DFSAll, SingleNodeNoEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0};
    EXPECT_EQ(g.DFSAll(), expected);
}

TEST(DFSAll, SingleNodeSingleEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {0}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0};
    EXPECT_EQ(g.DFSAll(), expected);
}

TEST(DFSAll, TwoNodeUnconnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}, {1, {}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(g.DFSAll(), expected);
}

TEST(DFSAll, TwoNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1}}, {1, {0}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(g.DFSAll(), expected);
}

TEST(DFSAll, MultipleNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 3}}, {1, {0}}, {2, {0, 3}}, {3, {0, 2}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0, 1, 2, 3};
    EXPECT_EQ(g.DFSAll(), expected);
}

TEST(DFSAll, MultipleNodeUnonnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 5}}, {1, {0}}, {2, {0}}, {3, {}}, {4, {5}}, {5, {0, 4}}};
    Graph g(adjacency_list);
    std::vector<int> expected = {0, 1, 2, 5, 4, 3};
    EXPECT_EQ(g.DFSAll(), expected);
}

//-----------------------------------------------------------------------------

TEST(IsPathBetweenNodes, EmptyGraph) {
    std::map<int, std::set<int>> adjacency_list;
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsPathBetweenNodes(0, 1));
}

TEST(IsPathBetweenNodes, SingleNodeNoEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsPathBetweenNodes(0, 1));
}

TEST(IsPathBetweenNodes, SingleNodeSingleEdgeNoPath) {
    std::map<int, std::set<int>> adjacency_list = {{0, {0}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsPathBetweenNodes(0, 1));
}

TEST(IsPathBetweenNodes, SingleNodeSingleEdgePath) {
    std::map<int, std::set<int>> adjacency_list = {{0, {0}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsPathBetweenNodes(0, 0));
}

TEST(IsPathBetweenNodes, TwoNodeUnconnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}, {1, {}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsPathBetweenNodes(0, 1));
}