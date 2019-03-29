/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (39.45%)
 * Total Accepted:    29.3K
 * Total Submissions: 74.2K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 * 
 * 
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 * 
 * 
 * 
 * Note:
 * 
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * 
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are “10,”0001”,”1”,”0”
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 * 
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 * 
 * 
 */
class Solution {
public:
    vector<pair<int, int>> counts;

    void convertToCounts(const vector<string>& strs) {
        for (auto& str : strs) {
            int c0 = 0, c1 = 0;
            for (auto ch : str) {
                if (ch == '0') {
                    ++c0;
                } else if (ch == '1') {
                    ++c1;
                }
            }
            counts.emplace_back({c0, c1});
        }
    }
    
    struct Key {
        int m;
        int n;
    };

    struct HashFn {
        size_t operator() (const Key& key) const {
            return (key.m << 16) | (key.n & 0xffff);
        }
    };

    unordered_map<int, unordered_map<Key, int, HashFn>> memo;

    int findMaxFormDP(int index, int count, int remain_m, int remain_n) {
        if (index >= counts.size()) {
            return (remain_m == 0 && remain_n == 0) ? count : 0;
        }
        if (remain_m == 0 && remain_n == 0) {
            return count;
        }
        if (remain_m < 0 && remain_n < 0) {
            return 0;
        }
        if (memo.find(index) != memo.end()) {
            if (memo[index].find(Key(remain_m, remain_n) != memo[index].end()) {
                return memo[index][Key(remain_m, remain_n)];
            }
        }

        count = max(findMaxFormDP(index + 1, count, remain_m, remain_n), 
            findMaxFormDP(index + 1, count + 1, remain_m - counts[index].first, remain_n - counts[index].second));
        
        memo[index][Key(remain_m, remain_n)] = count;
        return count;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        convertToCounts(strs);
        return findMaxFormDP(0, 0, m, n);
    }
};

