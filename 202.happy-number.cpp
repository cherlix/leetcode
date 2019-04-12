/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (44.68%)
 * Total Accepted:    222.8K
 * Total Submissions: 498.4K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */
class Solution {
public:
    bool isHappyRecursive(int n, unordered_set<int>& memo) {
        int num = 0;
        while (n > 0) {
            int digit = n % 10;
            num += digit * digit;
            n /= 10;
        }
        if (num == 1) {
            return true;
        } else if (memo.find(num) != memo.end()) {
            return false;
        } else {
            memo.insert(num);
            return isHappyRecursive(num, memo);
        }
    }

    bool isHappy(int n) {
        unordered_set<int> memo;
        return isHappyRecursive(n, memo);
    }
};

