/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (34.59%)
 * Total Accepted:    312.8K
 * Total Submissions: 903.3K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
class Solution {
public:
    map<int, bool> memo;
    
    set<string> generateDict(const vector<string>& list) {
        set<string> dict;
        for (auto& str : list) {
            dict.emplace(str);
        }
        return dict;
    }

    bool wordBreakDP(const string& s, const set<string>& dict, int start_index) {
        if (s.empty() || dict.find(s) != dict.end()) {
            return true;
        }

        if (memo.find(start_index) != memo.end()) {
            return false;
        }
        
        for (int i = 1; i < s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (dict.find(prefix) != dict.end()) {
                string suffix = s.substr(i);
                int index = start_index + i;
                if (wordBreakDP(suffix, dict, index)) {
                    return true;
                }

                memo.insert({index, false});
            }
        }

        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict = generateDict(wordDict);

        return wordBreakDP(s, dict, 0);
    }
};

