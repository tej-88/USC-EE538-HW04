#include "q.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

// Implement each function of `q.h` here.

std::unordered_map<std::pair<int, int>, int> memo;
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
                            const std::pair<int, int> end) {
                                int row_start = start.first;
                                int col_start = start.second;
                                int row_end = end.first;
                                int col_end = end.second;
                                int num_paths = FindNumberOfUniquePathsHelper(grid, row_start, col_start, row_end, col_end);
                                return num_paths;
                            }
                            
int FindNumberOfUniquePathsHelper(const std::vector<std::vector<int>> &grid, int row_start, int col_start, int row_end, int col_end) {
    // std::pair<int, int> start = {row_start, col_start};
    std::pair<int, int> end = {row_end, col_end};
    
    if (memo.count(end) > 0) {
        return memo[end];
    }
    else {

        if ((row_start == row_end) && (col_start == col_end)) {
            if (grid[row_end][col_end] == 0) {
                memo[end] = 0;
                return memo[end];
            }
            else {
                memo[end] = 1
                return memo[end];
            }
        }
        else if (row_start == row_end) {
            if (grid[row_end][col_end] == 0) {
                memo[end] = 0;
                return memo[end];
            }
            else {
                memo[end] = FindNumberOfUniquePathsHelper(grid, row_start, col_start, row_end, col_end - 1);
                return memo[end];
            }
        }
        else if (col_start == col_end) {
            if (grid[row_end][col_end] == 0) {
                memo[end] = 0;
                return memo[end];
            }
            else {
                memo[end] = FindNumberOfUniquePathsHelper(grid, row_start, col_start, row_end - 1, col_end);
                return memo[end];
            }
        }
        else {
            if (grid[row_end][col_end] == 0) {
                memo[end] = 0;
                return memo[end];
            }
            else {
                memo[end] = (FindNumberOfUniquePathsHelper(grid, row_start, col_start, row_end - 1, col_end) + FindNumberOfUniquePathsHelper(grid, row_start, col_start, row_end, col_end - 1));
                return memo[end];
            }
        }
    }
}