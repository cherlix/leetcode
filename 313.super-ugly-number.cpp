/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (40.81%)
 * Total Accepted:    57.9K
 * Total Submissions: 141.8K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * Write a program to find the n^th super ugly number.
 * 
 * Super ugly numbers are positive numbers whose all prime factors are in the
 * given prime list primes of size k.
 * 
 * Example:
 * 
 * 
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32 
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12 
 * ⁠            super ugly numbers given primes = [2,7,13,19] of size 4.
 * 
 * Note:
 * 
 * 
 * 1 is a super ugly number for any given primes.
 * The given numbers in primes are in ascending order.
 * 0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000.
 * The n^th super ugly number is guaranteed to fit in a 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (primes.size() == 0) {
            return -1;
        }

        if (n == 1) {
            return 1;
        }

        vector<int> uglys;
        int prime_index = 1;
        int ugly_index = 1;
        uglys.push_back(1);
        uglys.push_back(primes[0]);
        while (uglys.size() < n) {
            int num = uglys[1] * uglys[ugly_index];
            if (prime_index >= primes.size() || num < primes[prime_index]) {
                uglys.push_back(num);
            } else {
                uglys.push_back(primes[prime_index++]);
            }
            ++ugly_index;
        }

        return uglys[n - 1];
    }
};

