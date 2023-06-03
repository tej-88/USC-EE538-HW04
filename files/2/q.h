#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stack>

/**
 * This function is used by Google Test. Don't touch!
 */
template <class T>
void PrintCollection(T input, bool add_new_line = true) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }";
  if (add_new_line) {
    std::cout << std::endl;
  }
}
//-----------------------------------------------------------------------------
// The return value of BFS function.
// You don't need to change this struct, but the BFS function that you implement
// should return a value of this type, so please read and understand it.
struct BFSReturnValue {
  // Distance of root to each node.
  std::vector<int> distance;

  // Maps each node i to a path representing the shortest path from root to node
  // i.
  std::map<int, std::vector<int>> path;

  // The nodes that are visited in BFS order. Note that this is not used to mark
  // if a node is visited or not, but it is a vector that shows the order of the
  // nodes that are visited in BFS order. For example, in a graph with root 0
  // and children of root being 1, 2, the visited value after BFS should be:
  //
  //{0, 1, 2}
  std::vector<int> visited;
};

// Implement your own Graph class.
class Graph {
 public:
  //-----------------------------------------------------------------------------
  // The following functions are implemented. No need to touch!
  //-----------------------------------------------------------------------------
  // The constructor.
  Graph(std::map<int, std::set<int>> &adjacency_list)
      : adjacency_list_(adjacency_list) {}

  // Used to print the graph. Will be called by google test in auto grader.
  void Print() {
    std::cout << "Graph: {" << std::endl;
    for (auto e : adjacency_list_) {
      std::cout << "  " << e.first << ": ";
      PrintCollection(e.second, /*add_new_line=*/false);
      std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
  }

  //-----------------------------------------------------------------------------
  // TODO: Implement the following functions.
  //-----------------------------------------------------------------------------
  // Performs DFS search from root and returns the visited nodes in DFS order.
  // When there is a choice, the node with lower value should be visited first.

  std::vector<int> DFS(int root);

  // Performs DFS search on all nodes and returns the visited nodes in DFS
  // order. When there is a choice, the node with lower value should be visited
  // first. Note that this function does not take any inputs.
  std::vector<int> DFSAll();

  // Performs BFS search from root and returns a result of type BFSReturnValue,
  // which has the following:
  // 1. result.visited (vector): visited nodes in BFS order.
  // 2. result.path (map): a map of node i to a vector, where the vector is the
  // shortest path from root to i.
  // 3. result.distance (vector): element i represents the shortest distance
  // from root to node i.
  //
  // Assume root is a valid node in the graph.
  BFSReturnValue BFS(int root);

  // Returns true if there is at least one path between nodes i and j.
  // Assume i, j are valid nodes in the graph.
  bool IsPathBetweenNodes(int i, int j);

  // Returns true if the graph is bidirectional. A bidirectional graph is a
  // graph in which if edge (i,j) is in E, then the edge (j,i) is also in E.
  // An empty graph is considered bidirectional.
  // A graph of a single node is considered bidirectional.
  bool IsBidirectional();

  // Returns true if the graph is connected, i.e. if we start from each node, we
  // can get to any other node.
  bool IsConnected();

 private:
  std::map<int, std::set<int>> adjacency_list_;

  // Optionally you can implement and use these functions.
  void DFS_helper(int root, std::map<int, bool> &marks,
                  std::vector<int> &visited);

  void BFS_helper(int root, std::vector<int> &distance,
                  std::vector<int> &previous, std::vector<int> &visited);
};
