/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (46.71%)
 * Total Accepted:    59.6K
 * Total Submissions: 127.6K
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10^n.
 * 
 * 
 * Example:
 * 
 * 
 * Input: 2
 * Output: 91 
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100, 
 * excluding 11,22,33,44,55,66,77,88,99
 * 
 * 
 */
class Solution {
public:
    int countNumbersWithUniqueDigitsDP(int n) {
        if (n < 1) {
            return 0;
        }
        
        int count = countNumbersWithUniqueDigitsDP(n - 1);

        int this_count = 9;
        for (int i = 1; i < n; ++i) {
            this_count *= (10 - i);
        }

        return this_count + count;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        if (n < 1) {
            return 1;
        }
        
        int count = countNumbersWithUniqueDigitsDP(n - 1);

        int this_count = 9;
        for (int i = 1; i < n; ++i) {
            this_count *= (10 - i);
        }

        return this_count + count  + 1;
    }
};

