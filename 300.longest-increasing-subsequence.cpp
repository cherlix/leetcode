/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (40.47%)
 * Total Accepted:    210.8K
 * Total Submissions: 520K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 *  
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> blackboard(nums.size(), 1);
        int max_total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int max_val = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] <= nums[i]) {
                    max_val = max(blackboard[j], max_val);
                }
            }
            blackboard[i] = max_val + 1;
            max_total = max(max_total, blackboard[i]);
        }
        return max_total;
    }
};

