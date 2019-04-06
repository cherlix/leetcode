/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (52.30%)
 * Total Accepted:    81K
 * Total Submissions: 154.9K
 * Testcase Example:  '"USA"'
 *
 * 
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * 
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 * 
 */
class Solution {
public:
    enum State {
        INIT_STATE,
        FIRST_CAP_STATE,
        FIRST_NON_CAP_STATE,
        ONLY_FIRST_CAP_STATE,
        ALL_CAP_STATE
    };

    bool detectCapitalUse(string word) {
        if (word.size() == 1) {
            return true;
        }

        State state = INIT_STATE;
        if (word[0] >= 'A' && word[0] <= 'Z') {
            state = FIRST_CAP_STATE;
        } else {
            state = FIRST_NON_CAP_STATE;
        }

        if (state == FIRST_CAP_STATE) {
            if (word[1] >= 'A' && word[1] <= 'Z') {
                state = ALL_CAP_STATE;
            } else {
                state = ONLY_FIRST_CAP_STATE;
            }
        }

        bool result = true;
        for (int i = 1; i < word.size(); ++i) {
            if (state == FIRST_NON_CAP_STATE || state == ONLY_FIRST_CAP_STATE) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    result = false;
                    break;
                }
            } else if (state == ALL_CAP_STATE) {
                if (word[i] >= 'a' && word[i] <= 'z') {
                    result = false;
                    break;
                }
            }
        }

        return result;
    }
};

