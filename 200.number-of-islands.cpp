/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (40.67%)
 * Total Accepted:    319.6K
 * Total Submissions: 785.6K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
class Solution {
public:
    void visitIslandRecursive(int i, int j, const vector<vector<char>>& grid, vector<vector<bool>>& memo) {
        int row = i - 1, col = j;
        const vector<pair<int, int>> offsets {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
        for (auto& offset : offsets) {
            int row = offset.first;
            int col = offset.second;
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) {
                if (grid[row][col] == '1' && !memo[row][col]) {
                    memo[row][col] = true;
                    visitIslandRecursive(row, col, grid, memo);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() <= 0) {
            return 0;
        }
        vector<vector<bool>> memo(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '0' || memo[i][j]) {
                    continue;
                }

                ++count;
                memo[i][j] = true;
                visitIslandRecursive(i, j, grid, memo);
            }
        }
        return count;
    }
};

