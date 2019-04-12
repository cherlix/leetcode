/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (49.62%)
 * Total Accepted:    249.9K
 * Total Submissions: 503.4K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> memo;
        for (auto ch : s) {
            ++memo[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (memo[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

