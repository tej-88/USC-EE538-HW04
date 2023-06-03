#ifndef FILES_2_Q
#define FILES_2_Q
#include <iostream>
#include <map>
#include <string>
#include <vector>
// TODO: Implement the following functions in q.cc.

// On an m x n grid, where m is the number of rows and n is the number of
// columns. We want to know how many unique paths exists from start point to the
// end point. We can only move to the right or to the bottom direction. If a
// grid entry has 1, it means we can move to that location, otherwise, not.
//
// Example:
// Input grid: {1, 1, 1}, start = (0,0), end = (0, 2).
// Output: 1

// Input grid: {1, 0, 1}, start = (0,0), end = (0, 2).
// Output: 0

// Input grid: {
// {1, 1, 1},
// {1, 1, 1}
// }
// start = (0,0), end = (0, 2).
// Output: 3

// Input grid: {
// {1, 1, 1},
// {1, 0, 1}
// }
// start = (0,0), end = (0, 2).
// Output: 1

// Note: Assume m >= 1
// Hint: At each location in the graph we have two choices. Try to use this to
// write a recursive relationship.
int FindNumberOfUniquePaths(const std::vector<std::vector<int>> &grid,
                            const std::pair<int, int> start,
                            const std::pair<int, int> end);
                            
int FindNumberOfUniquePathsHelper(const std::vector<std::vector<int>> &grid, int row_start, int col_start, int row_end, int col_end);
#endif /* FILES_2_Q */
