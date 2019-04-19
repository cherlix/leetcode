/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (39.35%)
 * Total Accepted:    200.8K
 * Total Submissions: 509.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    void fillMatrix(vector<vector<int>>& matrix, int row, int col) {
        for (int i = 0; i < matrix[row].size(); ++i) {
            if (matrix[row][i] != 0) {
                matrix[row][i] = numeric_limits<int>::min() + 1;
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][col] != 0) {
                matrix[i][col] = numeric_limits<int>::min() + 1;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[row].size(); ++col) {
                if (matrix[row][col] == 0) {
                    fillMatrix(matrix, row, col);
                }
            }
        }
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[row].size(); ++col) {
                if (matrix[row][col] == numeric_limits<int>::min() + 1) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};

