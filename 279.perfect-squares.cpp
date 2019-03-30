/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (41.23%)
 * Total Accepted:    169.3K
 * Total Submissions: 410.7K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
class Solution {
public:
    int numSquares(int n) {
       vector<int> memo(n + 1, -1);
       return numSquaresDP(n, memo);
    }

    int numSquaresDP(int n, vector<int>& memo) {
        if (memo[n] != -1) {
            return memo[n];
        }

        const array<int, 4> constants {1, 2, 3, 1};
        if (n <= 4) {
            return constants[n - 1];
        }

        int number = sqrt(n);
        int count = numeric_limits<int>::max();
        for (int i = number; i >= 1; --i) {
            int remainder = n - i * i;

            if (remainder < 0) {
                continue;
            } else if (remainder == 0) {
                count = 0;
                break;
            } else {
                count = min(count, numSquaresDP(remainder, memo));
            }
        }

        memo[n] = count + 1;
        return memo[n];
    }
};

