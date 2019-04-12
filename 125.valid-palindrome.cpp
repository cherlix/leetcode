/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.66%)
 * Total Accepted:    338.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isCharacter(char ch) {
        return (ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (!isCharacter(s[l])) {
                ++l;
            } else if (!isCharacter(s[r])) {
                --r;
            } else if (tolower(s[l]) == tolower(s[r])) {
                ++l;
                --r;
            } else {
                return false;
            }
        }
        return true;
    }
};

