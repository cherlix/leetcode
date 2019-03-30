/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 *
 * https://leetcode.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (32.44%)
 * Total Accepted:    65K
 * Total Submissions: 200.5K
 * Testcase Example:  '"123"\n6'
 *
 * Given a string that contains only digits 0-9 and a target value, return all
 * possibilities to add binary operators (not unary) +, -, or * between the
 * digits so they evaluate to the target value.
 * 
 * Example 1:
 * 
 * 
 * Input: num = "123", target = 6
 * Output: ["1+2+3", "1*2*3"] 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = "232", target = 8
 * Output: ["2*3+2", "2+3*2"]
 * 
 * Example 3:
 * 
 * 
 * Input: num = "105", target = 5
 * Output: ["1*0+5","10-5"]
 * 
 * Example 4:
 * 
 * 
 * Input: num = "00", target = 0
 * Output: ["0+0", "0-0", "0*0"]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: num = "3456237490", target = 9191
 * Output: []
 * 
 * 
 */
class Solution {
public:
    bool evaluate(const string& str, int target) {
        deque<int> operands;
        deque<char> operators;
        for (int i = 0; i < str.size(); ) {
            if (ch >= '0' && ch <= '9') {
                operands.push_back(ch - '0');
                ++i;
            } else if (ch == '+' || ch == '-') {
                operators.push_back(ch);
                ++i;
            } else {
                int n = operands.back() * str[i + 1];
                operands.pop_back();
                operands.push_back(n);
                i += 2;
            }
        }
        
        int result = operands.front();
        while (!operands.empty()) {
            int n = operands.front();
            operands.pop_front();
            char ch = operators.front();
            operators.pop_front();
            if (ch == '+') {
                result += n;
            } else {
                result -= n;
            }
        }

        return result == target;
    }
    void calculate(vector<string>& equations, vector<string>& result, int target) {
        for (auto& str : equations) {
            if (evaluate(str, target)) {
                result.emplace_back(str);
            }
        }
    }
    void addOperatorsRecursive(string num, int index, int target, vector<string>& equations, vector<string>& result) {
        if (index == num.size()) {
            calculate(equations, result, target);
            return;
        }
        int size = equations.size();
        for (int i = 0; i < size; ++i) {
            equations.emplace_back(equations[i]);
        }
        for (int i = 0; i < size; ++i) {
            equations.emplace_back(equations[i]);
        }
        for (int i = 0; i < size; ++i) {
            equations[i] += "+";
            equations[i].append(num[index])
            equations[size + i] += "+";
            equations[size * 2 + i] += "+";
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;

        if (num.size() == 0) {
            return result;
        }

        vector<string> equations;
        equations.push_back(string(1, num[0]));
        addOperatorsRecursive(num, 1, target, equations, result);
        return result;
    }
};

