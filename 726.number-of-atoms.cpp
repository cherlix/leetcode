/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 *
 * https://leetcode.com/problems/number-of-atoms/description/
 *
 * algorithms
 * Hard (44.20%)
 * Total Accepted:    9.6K
 * Total Submissions: 21.7K
 * Testcase Example:  '"H2O"'
 *
 * Given a chemical formula (given as a string), return the count of each
 * atom.
 * 
 * An atomic element always starts with an uppercase character, then zero or
 * more lowercase letters, representing the name.
 * 
 * 1 or more digits representing the count of that element may follow if the
 * count is greater than 1.  If the count is 1, no digits will follow.  For
 * example, H2O and H2O2 are possible, but H1O2 is impossible.
 * 
 * Two formulas concatenated together produce another formula.  For example,
 * H2O2He3Mg4 is also a formula.  
 * 
 * A formula placed in parentheses, and a count (optionally added) is also a
 * formula.  For example, (H2O2) and (H2O2)3 are formulas.
 * 
 * Given a formula, output the count of all elements as a string in the
 * following form: the first name (in sorted order), followed by its count (if
 * that count is more than 1), followed by the second name (in sorted order),
 * followed by its count (if that count is more than 1), and so on.
 * 
 * Example 1:
 * 
 * Input: 
 * formula = "H2O"
 * Output: "H2O"
 * Explanation: 
 * The count of elements are {'H': 2, 'O': 1}.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * formula = "Mg(OH)2"
 * Output: "H2MgO2"
 * Explanation: 
 * The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: 
 * formula = "K4(ON(SO3)2)2"
 * Output: "K4N2O14S4"
 * Explanation: 
 * The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 * 
 * 
 * 
 * Note:
 * All atom names consist of lowercase letters, except for the first character
 * which is uppercase.
 * The length of formula will be in the range [1, 1000].
 * formula will only consist of letters, digits, and round parentheses, and is
 * a valid formula as defined in the problem.
 * 
 */
class Solution {
public:
    struct Token {
        string element;
        int count;
        bool is_element;
        bool is_compute_follow;
    };

    int processSubString(stack<Token>& memo, const string& formula, int index) {
        int count = 0;
        ++index;
        while ((index < formula.size()) && (formula[index] >= '0' && formula[index] <= '9')) {
            count = count * 10 + (formula[index] - '0');
            ++index;
        }

        if (count == 0) {
            count = 1;
        }
        stack<Token> cache;
        while (!memo.empty()) {
            auto& token = memo.top();
            if (token.is_element) {
                token.count *= count;
                cache.push(token);
                memo.pop();
            } else {
                memo.pop();
                break;
            }
        }

        while (!cache.empty()) {
            memo.push(cache.top());
            cache.pop();
        }

        return index;
    }

    string countOfAtoms(string formula) {
        stack<Token> memo;
        
        auto i = 0;
        while (i < formula.size()) {
            char ch = formula[i];
            if (ch == ')') {
               i = processSubString(memo, formula, i);
            } else if (ch >= 'A' && ch <= 'Z') {
                memo.push({string(1, ch), 1, true, false});
                ++i;
            } else if (ch >= 'a' && ch <= 'z') {
                auto& token = memo.top();
                token.element += ch;
                ++i;
            } else if (ch >= '0' && ch <= '9') {
                auto& token = memo.top();
                if (!token.is_compute_follow) {
                    token.count = (ch - '0');
                    token.is_compute_follow = true;
                } else {
                    token.count = token.count * 10 + (ch - '0');
                }
                ++i;
            } else if (ch == '(') {
                memo.push({"", 0, false, false});
                ++i;
            }
        }

        map<string, int> sort_tokens;
        while (!memo.empty()) {
            auto& token = memo.top();
            if (sort_tokens.count(token.element)) {
                sort_tokens[token.element] += token.count;   
            } else {
                sort_tokens.insert({token.element, token.count});
            }
            memo.pop();
        }

        string result;
        for (auto pair : sort_tokens) {
            result += pair.first;
            if (pair.second > 1)
                result += to_string(pair.second);
        }

        return result;
    }
};

