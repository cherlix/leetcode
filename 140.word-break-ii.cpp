/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (26.82%)
 * Total Accepted:    150.9K
 * Total Submissions: 562K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
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
    
    void addToResult(vector<string>& cache, vector<string>& result) {
        string str(cache[0]);

		for (int i = 1; i < cache.size(); ++i) {
			str += " ";
			str += cache[i];
		}

        result.emplace_back(str);
    }
    
    bool wordBreakDP(const string& s, 
                     const set<string>& dict, 
                     int start_index, 
                     vector<string>& cache, 
                     vector<string>& result) {
        if (s.empty()) {
            addToResult(cache, result);
            return true;
        }

        if (memo.find(start_index) != memo.end()) {
            return false;
        }
        
        bool has_valid = false;
        for (int i = 1; i <= s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (dict.find(prefix) != dict.end()) {
                cache.emplace_back(prefix);

                string suffix = s.substr(i);
                int index = start_index + i;
                
                if (!wordBreakDP(suffix, dict, index, cache, result)) {
                    memo.insert({index, false});
                } else {
                    has_valid = true;
                }

                cache.pop_back();
            }
        }
        
        return has_valid;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict = generateDict(wordDict);

        vector<string> result;
        vector<string> cache;
        wordBreakDP(s, dict, 0, cache, result);

        return result;
    }
};

