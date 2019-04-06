/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (43.34%)
 * Total Accepted:    88.8K
 * Total Submissions: 204.9K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0;
        string* shorter = &num1;
        string* longer = &num2;
        if (num1.size() > num2.size()) {
            swap(shorter, longer);
        }
        for (int i = shorter->size() - 1, j = longer->size() - 1; i >= 0; --i, --j) {
            int sum = int((*shorter)[i] - '0') + int((*longer)[j] - '0') + carry;
            carry = sum / 10;
            result = to_string(sum % 10) + result;
        }
        for (int i = longer->size() - shorter->size() - 1; i >= 0; --i) {
            int sum = int((*longer)[i] - '0') + carry;
            carry = sum / 10;
            result = to_string(sum % 10) + result;
        }
        if (carry > 0)  {
            result = to_string(carry) + result;
        }
        return result;
    }
};

