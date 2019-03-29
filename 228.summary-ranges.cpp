/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (35.44%)
 * Total Accepted:    126.6K
 * Total Submissions: 357.3K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int start = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (start == -1) {
                start = nums[i];
            }
            if (i + 1 >= nums.size() || nums[i] + 1 != nums[i + 1]) {
                if (start == nums[i]) {
                    result.emplace_back(to_string(start));
                } else {
                    result.emplace_back(to_string(start) + "->" + to_string(nums[i]));
                }
                start = -1;
            }
        }
        return result;
    }
};

