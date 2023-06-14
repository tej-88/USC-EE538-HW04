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
   EXPECT_FALSE(g.IsPathBetweenNodes(0, 1));
}

TEST(IsPathBetweenNodes, TwoNodeUnconnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}, {1, {}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsPathBetweenNodes(0, 1));
}

TEST(IsPathBetweenNodes, TwoNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1}}, {1, {0}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsPathBetweenNodes(0, 1));
}

TEST(IsPathBetweenNodes, MultipleNodeConnectedNoPath) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 3}}, {1, {0}}, {2, {0, 3}}, {3, {0, 2}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsPathBetweenNodes(3, 1));
}

TEST(IsPathBetweenNodes, MultipleNodeConnectedPath) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 3}}, {1, {0}}, {2, {0, 3}}, {3, {0, 2}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsPathBetweenNodes(0, 1));
}

TEST(IsPathBetweenNodes, MultipleNodeUnonnectedNoPath) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 5}}, {1, {0}}, {2, {0}}, {3, {}}, {4, {5}}, {5, {0, 4}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsPathBetweenNodes(0, 3));
}

TEST(IsPathBetweenNodes, MultipleNodeUnonnectedPath) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 5}}, {1, {0}}, {2, {0}}, {3, {}}, {4, {5}}, {5, {0, 4}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsPathBetweenNodes(0, 4));
}

//-----------------------------------------------------------------------------

TEST(IsBidirectional, EmptyGraph) {
    std::map<int, std::set<int>> adjacency_list;
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsBidirectional());
}

TEST(IsBidirectional, SingleNodeNoEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsBidirectional());
}

TEST(IsBidirectional, SingleNodeSingleEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {0}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsBidirectional());
}

TEST(IsBidirectional, TwoNodeUnconnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}, {1, {}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsBidirectional());
}

TEST(IsBidirectional, TwoNodeConnectedBidirectional) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1}}, {1, {0}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsBidirectional());
}

TEST(IsBidirectional, TwoNodeConnectedNotBidirectional) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1}}, {1, {}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsBidirectional());
}

TEST(IsBidirectional, MultipleNodeNotBidirectional) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 3}}, {1, {0}}, {2, {0, 3}}, {3, {0}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsBidirectional());
}

TEST(IsBidirectional, MultipleNodeBidirectional) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 3}}, {1, {0}}, {2, {0, 3}}, {3, {0, 2}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsBidirectional());
}

//-----------------------------------------------------------------------------

TEST(IsConnected, EmptyGraph) {
    std::map<int, std::set<int>> adjacency_list;
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsConnected());
}

TEST(IsConnected, SingleNodeNoEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsConnected());
}

TEST(IsConnected, SingleNodeSingleEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {0}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsConnected());
}

TEST(IsConnected, TwoNodeUnconnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}, {1, {}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsConnected());
}

TEST(IsConnected, TwoNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1}}, {1, {0}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsConnected());
}

TEST(IsConnected, MultipleNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 3}}, {1, {0}}, {2, {0, 3}}, {3, {0}}};
    Graph g(adjacency_list);
    EXPECT_TRUE(g.IsConnected());
}

TEST(IsConnected, MultipleNodeNotConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2, 3}}, {1, {3}}, {2, {0, 3}}, {3, {1}}};
    Graph g(adjacency_list);
    EXPECT_FALSE(g.IsConnected());
}

//-----------------------------------------------------------------------------

TEST(BFS, EmptyGraph) {
    std::map<int, std::set<int>> adjacency_list;
    Graph g(adjacency_list);
    std::vector<int> expected_distance;
    std::map<int, std::vector<int>> expected_path;
    std::vector<int> expected_visited;

    auto bfs_result = g.BFS(0);

    EXPECT_EQ(expected_distance, bfs_result.distance);
    EXPECT_EQ(expected_path, bfs_result.path);
    EXPECT_EQ(expected_visited, bfs_result.visited);
}

TEST(BFS, SingleNodeNoEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}};
    Graph g(adjacency_list);
    std::vector<int> expected_distance = {0};
    std::map<int, std::vector<int>> expected_path = {{0, {}}};
    std::vector<int> expected_visited = {0};

    auto bfs_result = g.BFS(0);

    EXPECT_EQ(expected_distance, bfs_result.distance);
    EXPECT_EQ(expected_path, bfs_result.path);
    EXPECT_EQ(expected_visited, bfs_result.visited);
}

TEST(BFS, SingleNodeSingleEdge) {
    std::map<int, std::set<int>> adjacency_list = {{0, {0}}};
    Graph g(adjacency_list);
    std::vector<int> expected_distance = {0};
    std::map<int, std::vector<int>> expected_path = {{0, {}}};
    std::vector<int> expected_visited = {0};

    auto bfs_result = g.BFS(0);

    EXPECT_EQ(expected_distance, bfs_result.distance);
    EXPECT_EQ(expected_path, bfs_result.path);
    EXPECT_EQ(expected_visited, bfs_result.visited);
}

TEST(BFS, TwoNodeUnconnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {}}, {1, {}}};
    Graph g(adjacency_list);
    std::vector<int> expected_distance = {0, 0};
    std::map<int, std::vector<int>> expected_path = {{0, {}}, {1, {}}};
    std::vector<int> expected_visited = {0};

    auto bfs_result = g.BFS(0);

    EXPECT_EQ(expected_distance, bfs_result.distance);
    EXPECT_EQ(expected_path, bfs_result.path);
    EXPECT_EQ(expected_visited, bfs_result.visited);
}

TEST(BFS, TwoNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1}}, {1, {0}}};
    Graph g(adjacency_list);
    std::vector<int> expected_distance = {0, 1};
    std::map<int, std::vector<int>> expected_path = {{0, {}}, {1, {0, 1}}};
    std::vector<int> expected_visited = {0, 1};

    auto bfs_result = g.BFS(0);

    EXPECT_EQ(expected_distance, bfs_result.distance);
    EXPECT_EQ(expected_path, bfs_result.path);
    EXPECT_EQ(expected_visited, bfs_result.visited);
}

TEST(BFS, MultipleNodeConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {1, 2}}, {1, {0}}, {2, {0, 3}}, {3, {0, 2}}};
    Graph g(adjacency_list);
    std::vector<int> expected_distance = {0, 1, 1, 2};
    std::map<int, std::vector<int>> expected_path = {{0, {}}, {1, {0, 1}}, {2, {0, 2}}, {3, {0, 2, 3}}};
    std::vector<int> expected_visited = {0, 1, 2, 3};

    auto bfs_result = g.BFS(0);

    EXPECT_EQ(expected_distance, bfs_result.distance);
    EXPECT_EQ(expected_path, bfs_result.path);
    EXPECT_EQ(expected_visited, bfs_result.visited);
}

TEST(BFS, MultipleNodeNotConnected) {
    std::map<int, std::set<int>> adjacency_list = {{0, {2, 3}}, {1, {4}}, {2, {0, 3}}, {3, {0, 2}}, {4, {1}}};
    Graph g(adjacency_list);
    std::vector<int> expected_distance = {0, 0, 1, 1, 0};
    std::map<int, std::vector<int>> expected_path = {{0, {}}, {1, {}}, {2, {0, 2}}, {3, {0, 3}}, {4, {}}};
    std::vector<int> expected_visited = {0, 2, 3};

    auto bfs_result = g.BFS(0);

    EXPECT_EQ(expected_distance, bfs_result.distance);
    EXPECT_EQ(expected_path, bfs_result.path);
    EXPECT_EQ(expected_visited, bfs_result.visited);
}