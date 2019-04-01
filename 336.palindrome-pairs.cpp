/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (30.46%)
 * Total Accepted:    64.6K
 * Total Submissions: 211.9K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]] 
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]] 
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    struct Result {
        bool ij_is_pair;
        bool ji_is_pair;
    };

    Result isPalindromes(const string* word1, const string* word2) {
        Result result;
        result.ij_is_pair = true;
        result.ji_is_pair = true;
        bool is_swap = false;
        if (word1->size() > word2->size()) {
            swap(word1, word2);
            is_swap = true;
        }
        for (int i = 0; i < word1->size(); ++i) {
            if ((*word1)[i] != (*word2)[word2->size() - i - 1]) {
                result.ij_is_pair = false;
                break;
            }
        }
        if (result.ij_is_pair) {
            for (int i = 0; i < (word2->size() - word1->size()) / 2; ++i) {
                if ((*word2)[i] != (*word2)[word2->size() - word1->size() - 1 - i]) {
                    result.ij_is_pair = false;
                    break;
                }
            }
        }
        for (int i = 0; i < word1->size(); ++i) {
            if ((*word2)[i] != (*word1)[word1->size() - i - 1]) {
                result.ji_is_pair = false;
                break;
            }
        }
        if (result.ji_is_pair) {
            for (int i = word1->size(); i < word1->size() + (word2->size() - word1->size()) / 2; ++i) {
                if ((*word2)[i] != (*word2)[word2->size() - 1 - i]) {
                    result.ji_is_pair = false;
                    break;
                }
            }
        }
        if (is_swap) {
            swap(result.ij_is_pair, result.ji_is_pair);
        }
        return result;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                Result res = isPalindromes(&words[i], &words[j]);

                if (res.ij_is_pair) {
                    result.emplace_back(vector<int>() = {i, j});
                } else if (res.ji_is_pair) {
                    result.emplace_back(vector<int>() = {j, i});
                }
            }
        }

        return result;
    }
};

