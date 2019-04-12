/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 *
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (28.70%)
 * Total Accepted:    17.4K
 * Total Submissions: 60.7K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * Given an integer array, return the k-th smallest distance among all the
 * pairs. The distance of a pair (A, B) is defined as the absolute difference
 * between A and B. 
 * 
 * Example 1:
 * 
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0 
 * Explanation:
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 * 
 * 
 * 
 * Note:
 * 
 * 2 .
 * 0 .
 * 1 .
 * 
 * 
 */

// Note:
// 1. Review the second hightest discussion.

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = numeric_limits<int>::max();
        int i = 1;
        while (i < nums.size()) {
            l = min(l, nums[i] - nums[i - 1]);
            ++i;
        }

        int r = nums[nums.size() - 1] - nums[0];

        while (l < r) {
            int mid = l + (r - l) / 2;

            int count = 0;
            for (int i = 0, j = 1; i < nums.size(); ++i) {
                while (j < nums.size() && nums[j] - nums[i] <= mid) ++j;

                count += j - i - 1;
            }
            
            // Review upper_bound and lower_bound implementation of STL. It helps to understand the logic.
            // If try to terminate binary search, use the pattern below. set right to middle.
            if (count < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};

