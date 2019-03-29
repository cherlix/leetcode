/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (32.03%)
 * Total Accepted:    99.1K
 * Total Submissions: 309.6K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * Example 1:
 * 
 * 
 * Input: "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 2-1 + 2 "
 * Output: 3
 * 
 * Example 3:
 * 
 * 
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */
class Solution {
public:
	int calculate(string s) {
		stack<char> operators;
		stack<int> operands;

		for (auto i = 0; i < s.size();) {
			char ch = s[i];
			if (ch == ' ') {
				++i;
			}
			else if (ch == '(' || ch == '+' || ch == '-') {
				operators.push(ch);
				++i;
			}
			else if (ch == ')') {
				operators.pop();
				if (!operators.empty()) {
					char op = operators.top();
					if (op == '+' || op == '-') {
						int val0 = operands.top();
						operands.pop();
						int val1 = operands.top();
						operands.pop();
						if (op == '+') {
							val0 += val1;
						}
						else {
							val0 = val1 - val0;
						}
						operands.push(val0);
						operators.pop();
					}
				}
				++i;
			}
			else {
				int j = i;
				int val = 0;
				while (s[j] >= '0' && s[j] <= '9') {
					val = s[j] - '0' + val * 10;
					++j;
				}
				if (!operators.empty()) {
					char op = operators.top();
					if (op == '+') {
						val += operands.top();
						operators.pop();
						operands.pop();
					}
					else if (op == '-') {
						val = operands.top() - val;
						operators.pop();
						operands.pop();
					}
					operands.push(val);
				}
				else {
					operands.push(val);
				}
				i = j;
			}
		}

		return operands.top();
	}
};

