#include "q.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

// Implement each function of `q.h` here.

// Performs DFS search from root and returns the visited nodes in DFS order.
// When there is a choice, the node with lower value should be visited first.

std::vector<int> Graph::DFS(int root) {
    std::vector<int> visited;
    std::map<int, bool> marks;
    DFS_helper(root, marks, visited);
    return visited;
}

// Optionally you can implement and use these functions.
void Graph::DFS_helper(int root, std::map<int, bool> &marks,
                std::vector<int> &visited) {
                    if (adjacency_list_.count(root) == 0) {
                        return;
                    }
                    if (marks[root]) {
                        return;
                    }
                    else {
                        visited.push_back(root);
                        marks[root] = true;
                        auto neighbors = adjacency_list_[root];
                        for (const auto &neighbor : neighbors) {
                            DFS_helper(neighbor, marks, visited);
                        }
                        return;
                    }
                }

// Performs DFS search on all nodes and returns the visited nodes in DFS
// order. When there is a choice, the node with lower value should be visited
// first. Note that this function does not take any inputs.
std::vector<int> Graph::DFSAll() {
    std::vector<int> visited;

    for (const auto &node : adjacency_list_) {
        auto vec_iter = std::find(visited.begin(), visited.end(), node.first);
        if (vec_iter == visited.end()) {
            auto visited_sub = DFS(node.first);
            for (const auto &n_sub : visited_sub) {
                visited.push_back(n_sub);
            }
        }
    }

    return visited;
}

// Returns true if there is at least one path between nodes i and j.
// Assume i, j are valid nodes in the graph.
bool Graph::IsPathBetweenNodes(int i, int j) {
    std::vector<int> i_dfs = DFS(i);
    auto iter = std::find(i_dfs.begin(), i_dfs.end(), j);
    if (iter == i_dfs.end()) {
        return false;
    }
    else {
        return true;
    }
}

// Returns true if the graph is bidirectional. A bidirectional graph is a
// graph in which if edge (i,j) is in E, then the edge (j,i) is also in E.
// An empty graph is considered bidirectional.
// A graph of a single node is considered bidirectional.
bool Graph::IsBidirectional() {
    if (adjacency_list_.size() == 0) {
        return true;
    }
    else if (adjacency_list_.size() == 1) {
        return true;
    }
    else {
        for (const auto &x : adjacency_list_) {
            auto node_one = x.first;
            for (const auto &node_two : x.second) {
                auto node_two_edges = adjacency_list_[node_two];
                auto iter = std::find(node_two_edges.begin(), node_two_edges.end(), node_one);
                if (iter == node_two_edges.end()) {
                    return false;
                }
            }
        }
        return true;
    }
}