/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.10%)
 * Total Accepted:    128.2K
 * Total Submissions: 250.9K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int getSum(int a, int b) {
        const int n = sizeof(int) * 8;
        int index = n;
        int result = 0;
        int carry = 0;
        while (index-- > 0) {
            int val = (a & 0x1) + (b & 0x1) + carry;
            result += (val & 0x1)  << (n - index - 1);

            carry = (val >> 1);
            a >>= 1;
            b >>= 1;
        }

        return result;
    }
};

