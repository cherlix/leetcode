/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (39.16%)
 * Total Accepted:    48.4K
 * Total Submissions: 123.5K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * Given an array consisting of n integers, find the contiguous subarray of
 * given length k that has the maximum average value. And you need to output
 * the maximum average value.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
		double max_val = numeric_limits<int>::min();
		if (k >= nums.size()) {
            max_val = 0.0;
			for (size_t i = 0; i < nums.size(); i++)
			{
				max_val += nums[i];
			}
			max_val /= nums.size();
		} else {
			double sum = 0.0;
			for (size_t i = 0; i + k <= nums.size(); i++) {
				if (i > 0) {
					sum -= ((double)nums[i - 1]) / k;
					sum += ((double)nums[i + k - 1]) / k;
				} else {
					for (size_t j = i; j < k; ++j) {
						sum += ((double)nums[j]) / k;
					}
				}
				max_val = max(max_val, sum);
			}
		}

		return max_val;
    }
};

