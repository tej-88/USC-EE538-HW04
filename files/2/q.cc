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

// Performs BFS search from root and returns a result of type BFSReturnValue,
// which has the following:
// 1. result.visited (vector): visited nodes in BFS order.
// 2. result.path (map): a map of node i to a vector, where the vector is the
// shortest path from root to i.
// 3. result.distance (vector): element i represents the shortest distance
// from root to node i.
//
// Assume root is a valid node in the graph.
BFSReturnValue Graph::BFS(int root) {
    std::vector<int> distance(adjacency_list_.size(), 0);
    std::vector<int> previous(adjacency_list_.size(), -1);
    std::vector<int> visited;
    std::map<int, std::vector<int>> path;

    BFS_helper(root, distance, previous, visited);

    for (const auto &x : adjacency_list_) {
        std::vector<int> p;
        int current_node = x.first;

        if (current_node != root) {
            while (previous[current_node] != -1) {
                p.push_back(current_node);
                current_node = previous[current_node];
            }
            if (current_node == root) {
                p.push_back(current_node);
            }
            std::reverse(p.begin(), p.end());
        } 
        path[x.first] = p;
    }

    BFSReturnValue result;
    result.distance = distance;
    result.path = path;
    result.visited =  visited;
    return result;
}

void Graph::BFS_helper(int root, std::vector<int> &distance,
                  std::vector<int> &previous, std::vector<int> &visited) {
                    if (adjacency_list_.count(root) == 0) {
                        return;
                    }
                    else {
                        std::queue<int> bfs_q;
                        std::map<int, bool> is_visited;
                        bfs_q.push(root);
                        is_visited[root] = true;

                        while(!bfs_q.empty()) {
                            int current_node = bfs_q.front();
                            bfs_q.pop();
                            visited.push_back(current_node);
                            for (const auto &x : adjacency_list_[current_node]) {
                                if(is_visited.count(x) == 0) {
                                    bfs_q.push(x);
                                    previous[x] = current_node;
                                    distance[x] = distance[current_node] + 1;
                                    is_visited[x] = true;
                                }
                            }
                        }
                        return;
                    }
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

// Returns true if the graph is connected, i.e. if we start from each node, we
// can get to any other node.
bool Graph::IsConnected() {
    std::vector<bool> visited(adjacency_list_.size(), false);

    for (const auto &x : adjacency_list_) {
        visited[x.first] = true;
        for (const auto &y : adjacency_list_) {
            if (!visited[y.first]) {
                if (!IsPathBetweenNodes(x.first, y.first)) {
                    return false;
                }
            }
        }
    } 
    return true;
}