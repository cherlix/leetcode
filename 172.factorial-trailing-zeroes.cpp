/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (37.31%)
 * Total Accepted:    151.9K
 * Total Submissions: 407.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int count = n % 10 < 5 ? 0 : 1;
        int multiple = 2;
        n /= 10;
        while (n > 0) {
            count += (n % 10) * (multiple + 1);
            multiple *= 10;
            n /= 10;
        }
        return count;
    }
};

