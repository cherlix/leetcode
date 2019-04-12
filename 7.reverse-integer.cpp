/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.23%)
 * Total Accepted:    654.6K
 * Total Submissions: 2.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
		int result = 0;
		
        const int limit = numeric_limits<int>::max() / 10;
		const int last_digit = numeric_limits<int>::max() % 10;

		const int limit_negtive = numeric_limits<int>::min() / 10;
		const int last_digit_negtive = numeric_limits<int>::min() % 10;

		int tmp = x;
		while (tmp != 0) {
			result *= 10;
			result += (tmp % 10);
			tmp /= 10;

			if ((x > 0 && ((result > limit && tmp != 0) || ((result == limit) && (last_digit < tmp)))) ||
				(x < 0 && ((result < limit_negtive && tmp != 0) || ((result == limit_negtive) && (last_digit_negtive > tmp))))) {
				return 0;
			}
		}

		return result;
    }
};

