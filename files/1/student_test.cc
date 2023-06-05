#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(FindNumberOfUniquePaths, SingleRowNoObtacle) {
    std::vector<std::vector<int>> grid = {{1, 1, 1}};
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> end = {0, 2};
    int actual = FindNumberOfUniquePaths(grid, start, end);
    EXPECT_EQ(actual, 1);
}

TEST(FindNumberOfUniquePaths, SingleRowWithObtacle) {
    std::vector<std::vector<int>> grid = {{1, 0, 1}};
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> end = {0, 2};
    int actual = FindNumberOfUniquePaths(grid, start, end);
    EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePaths, TwoByThreeNoObtacle) {
    std::vector<std::vector<int>> grid = {
                                            {1, 1, 1},
                                            {1, 1, 1}
                                        };
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> end = {1, 2};
    int actual = FindNumberOfUniquePaths(grid, start, end);
    EXPECT_EQ(actual, 3);
}

TEST(FindNumberOfUniquePaths, TwoByThreeWithObtacle) {
    std::vector<std::vector<int>> grid = {
                                            {1, 1, 1},
                                            {1, 0, 1}
                                        };
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> end = {1, 2};
    int actual = FindNumberOfUniquePaths(grid, start, end);
    EXPECT_EQ(actual, 1);
}

TEST(FindNumberOfUniquePaths, SourceObstacle) {
    std::vector<std::vector<int>> grid = {
                                            {0, 1, 1},
                                            {1, 1, 1}
                                        };
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> end = {1, 2};
    int actual = FindNumberOfUniquePaths(grid, start, end);
    EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePaths, DestinationObstacle) {
    std::vector<std::vector<int>> grid = {
                                            {1, 1, 1},
                                            {1, 1, 0}
                                        };
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> end = {1, 2};
    int actual = FindNumberOfUniquePaths(grid, start, end);
    EXPECT_EQ(actual, 0);
}