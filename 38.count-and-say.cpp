/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.82%)
 * Total Accepted:    271.1K
 * Total Submissions: 677.5K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        int count = 1;
        string number = "1";
        while (++count <= n) {
            string temp = "";
            int index = 0;
            char current = number[0];
            int num_count = 1;
            while (++index <= number.size()) {
                if (index == number.size() || number[index] != current) {
                    temp += char(num_count + '0');
                    temp += current;
                    current = index < number.size() ? number[index] : 0;
                    num_count = 1;
                } else {
                    ++num_count;
                }
            }
            number = temp;
        }
        return number;
    }
};

