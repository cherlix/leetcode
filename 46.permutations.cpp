/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.26%)
 * Total Accepted:    359.5K
 * Total Submissions: 661.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    void generatePermute(vector<vector<int>>& results, vector<int>& result, vector<int>& nums) {
        if (nums.size() == 0) {
            results.emplace_back(result);
            return;
        }

        vector<int> temp(nums.size() - 1, 0);
        copy(nums.begin() + 1, nums.end(), temp.begin());
        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(nums[i]);
            generatePermute(results, result, temp);
            if (temp.size() > i) {
                temp[i] = nums[i];
            }
            result.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        generatePermute(results, result, nums);
        return results;
    }
};

