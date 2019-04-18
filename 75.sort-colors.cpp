/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (41.70%)
 * Total Accepted:    306.2K
 * Total Submissions: 732.9K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr_0 = 0;
        int ptr_2 = nums.size() - 1;
        int cur_ptr = 0;
        while (cur_ptr <= ptr_2) {
            if (nums[cur_ptr] == 0) {
                swap(nums[cur_ptr], nums[ptr_0]);
                ++cur_ptr;
                ++ptr_0;
            } else if (nums[cur_ptr] == 1) {
                ++cur_ptr;
            } else {
                swap(nums[cur_ptr], nums[ptr_2]);
                --ptr_2;
            }
        }
    }
};

