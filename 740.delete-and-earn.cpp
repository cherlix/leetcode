/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 *
 * https://leetcode.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (45.42%)
 * Total Accepted:    20K
 * Total Submissions: 44K
 * Testcase Example:  '[3,4,2]'
 *
 * Given an array nums of integers, you can perform operations on the array.
 * 
 * In each operation, you pick any nums[i] and delete it to earn nums[i]
 * points. After, you must delete every element equal to nums[i] - 1 or nums[i]
 * + 1.
 * 
 * You start with 0 points. Return the maximum number of points you can earn by
 * applying such operations.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3, 4, 2]
 * Output: 6
 * Explanation: 
 * Delete 4 to earn 4 points, consequently 3 is also deleted.
 * Then, delete 2 to earn 2 points. 6 total points are earned.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2, 2, 3, 3, 3, 4]
 * Output: 9
 * Explanation: 
 * Delete 3 to earn 3 points, deleting both 2's and the 4.
 * Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
 * 9 total points are earned.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of nums is at most 20000.
 * Each element nums[i] is an integer in the range [1, 10000].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int deleteAndEarnDP(const vector<int>& blackboard, vector<pair<int, int>>& memo, int n, bool taken) {
        if (n == 1) {
            return taken ? 0 : blackboard[1];
        }

        if (memo[n].first != -1 && taken) {
            return memo[n].first;
        } else if (memo[n].second != -1 && !taken) {
            return memo[n].second;
        }

        if (taken) {
            memo[n].first = deleteAndEarnDP(blackboard, memo, n - 1, false);
            return memo[n].first;
        } else {
            int val0 = deleteAndEarnDP(blackboard, memo, n - 1, true) + blackboard[n];
            int val1 = deleteAndEarnDP(blackboard, memo, n - 1, false);
            memo[n].second = max(val0, val1);
            return memo[n].second;
        }
    }

    int deleteAndEarn(vector<int>& nums) {
        vector<int> blackboard(10001, 0);
        vector<pair<int, int>> memo(10001, pair(-1, -1));
        for (auto num : nums) {
            blackboard[num] += num;
        }

        int val0 = deleteAndEarnDP(blackboard, memo, 10000, true);
        int val1 = deleteAndEarnDP(blackboard, memo, 10000, false);
        return max(val0, val1);
    }
};

