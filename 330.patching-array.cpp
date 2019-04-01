/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 *
 * https://leetcode.com/problems/patching-array/description/
 *
 * algorithms
 * Hard (33.21%)
 * Total Accepted:    30.5K
 * Total Submissions: 92K
 * Testcase Example:  '[1,3]\n6'
 *
 * Given a sorted positive integer array nums and an integer n, add/patch
 * elements to the array such that any number in range [1, n] inclusive can be
 * formed by the sum of some elements in the array. Return the minimum number
 * of patches required.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3], n = 6
 * Output: 1 
 * Explanation:
 * Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3,
 * 4.
 * Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3],
 * [2,3], [1,2,3].
 * Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
 * So we only need 1 patch.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,5,10], n = 20
 * Output: 2
 * Explanation: The two patches can be [2, 4].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,2], n = 5
 * Output: 0
 * 
 */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;
        int cur_max_num = 0;
        int cur_index = 0;
        while (cur_index < nums.size() && cur_max_num < n) {
            if (cur_max_num + 1 < nums[cur_index]) {
                ++count;
                cur_max_num += cur_max_num + 1;
            } else {
                cur_max_num += nums[cur_index];
                ++cur_index;
            }
        }
        while (cur_max_num < n) {
            if (cur_max_num < (numeric_limits<int>::max()- 1) / 2)
            {
                cur_max_num += cur_max_num + 1;
                ++count;
            } else {
                ++count;
                break;
            }
        }
        return count;        
    }
};

// After look at discussion, then find the solution. It is a greedy algorithm.

