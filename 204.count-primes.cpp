/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (28.62%)
 * Total Accepted:    225K
 * Total Submissions: 786.2K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        
        vector<bool> is_primes(n + 1, true);
        int count = 0;
        int index = 2;
        while (index < n) {
            if (is_primes[index]) {
                ++count;
                int counter = 2;
                while (counter * index < n) { 
                    is_primes[counter * index] = false;
                    ++counter;
                }
            }
            ++index;
        }
        return count;
    }
};

