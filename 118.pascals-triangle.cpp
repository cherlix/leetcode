/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (45.21%)
 * Total Accepted:    240.2K
 * Total Submissions: 530.9K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        result.push_back(vector<int>() = {1});
        for (int i = 1; i < numRows; ++i) {
            vector<int>& last_row = result[i - 1];
            vector<int> vec;
            vec.push_back(1);
            for (int j = 0; j < last_row.size() - 1; ++j) {
                vec.push_back(last_row[j] + last_row[j + 1]);
            }
            vec.push_back(1);
            result.emplace_back(vec);
        }
        return result;        
    }
};

