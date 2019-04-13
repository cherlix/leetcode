/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (51.87%)
 * Total Accepted:    348.4K
 * Total Submissions: 670.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            int size = result.size();
            for (int j = 0; j < size; ++j) {
                vector<int> vec = result[j];
                vec.push_back(nums[i]);
                result.push_back(vec);
            }
            result.push_back(vector<int>() = {nums[i]});
        }
        result.push_back(vector<int>());
        return result;
    }
};

