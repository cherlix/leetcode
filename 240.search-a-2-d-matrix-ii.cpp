/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (40.54%)
 * Total Accepted:    171.1K
 * Total Submissions: 421.5K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
class Solution {
public:
    bool findLowerBound(const vector<vector<int>>& matrix, int row, int col, int target) {
        if (col < 0) {
            return false;
        }
        
        int l = row, r = matrix.size() - 1;
        if (matrix[r][col] < target) {
            return false;
        }

        while (l < r) {
            int m = l + (r - l) / 2;
            if (matrix[m][col] == target) {
                return true;
            } else if (matrix[m][col] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (l < matrix.size() && matrix[l][col] == target) {
            return true;
        } else if (col == 0 || l >= matrix.size()) {
            return false;
        } else {
            return findLowerBound(matrix, l, col - 1, target);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        return findLowerBound(matrix, 0, matrix[0].size() - 1, target);
    }
};

