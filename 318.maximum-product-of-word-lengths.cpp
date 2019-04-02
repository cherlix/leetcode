/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (48.03%)
 * Total Accepted:    76.8K
 * Total Submissions: 159.9K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 * 
 * Example 1:
 * 
 * 
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16 
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * Example 2:
 * 
 * 
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4 
 * Explanation: The two words can be "ab", "cd".
 * 
 * Example 3:
 * 
 * 
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0 
 * Explanation: No such pair of words.
 * 
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<char, set<int>> memo;
        vector<vector<bool>> board(words.size(), vector<bool>(words.size(), false));

        for (int i = 0; i < words.size(); ++i) {
            for (auto ch : words[i]) {
                if (memo.find(ch) != memo.end()) {
                    for (auto index : memo[ch]) {
                        board[i][index] = true;
                        board[index][i] = true;
                    }
                } 
                memo[ch].insert(i);
            }
        }

        int max_product = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (board[i][j] == false) {
                    max_product = max(max_product, words[i].size() * words[j].size());
                }
            }
        }

        return max_product;
    }
};

