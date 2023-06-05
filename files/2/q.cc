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
                    else if (marks[root]) {
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
        auto vec_iter = std::find(visited.begin(), visited.end(), node);
        if (vec_iter == visited.end()) {
            auto visited_sub = DFS(node);
            for (const auto &n_sub : visited_sub) {
                visited.push_back(n_sub);
            }
        }
    }

    return visited;
}