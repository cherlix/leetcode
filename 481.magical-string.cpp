/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 *
 * https://leetcode.com/problems/magical-string/description/
 *
 * algorithms
 * Medium (45.83%)
 * Total Accepted:    17.8K
 * Total Submissions: 38.8K
 * Testcase Example:  '1'
 *
 * 
 * A magical string S consists of only '1' and '2' and obeys the following
 * rules:
 * 
 * 
 * The string S is magical because concatenating the number of contiguous
 * occurrences of characters '1' and '2' generates the string S itself.
 * 
 * 
 * 
 * The first few elements of string S is the following:
 * S = "1221121221221121122……"
 * 
 * 
 * 
 * If we group the consecutive '1's and '2's in S, it will be:
 * 
 * 
 * 1   22  11  2  1  22  1  22  11  2  11  22 ......
 * 
 * 
 * and the occurrences of '1's or '2's in each group are:
 * 
 * 
 * 1   2       2    1   1    2     1    2     2    1    2    2 ......
 * 
 * 
 * 
 * You can see that the occurrence sequence above is the S itself. 
 * 
 * 
 * 
 * Given an integer N as input, return the number of '1's in the first N number
 * in the magical string S.
 * 
 * 
 * Note:
 * N will not exceed 100,000.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 6
 * Output: 3
 * Explanation: The first 6 elements of magical string S is "12211" and it
 * contains three 1's, so return 3.
 * 
 * 
 */
class Solution {
public:
    int magicalString(int n) {
        if (n == 0) {
            return 0;
        }
        
        if (n <= 3) {
            return 1;
        }
        
        string buffer("122");
        int count = 1;
        int seq_index = 2;
        while (buffer.size() < n) {
            int last_val = buffer[buffer.size() - 1] - '0';
            int new_val = last_val ^ 3;
            if (buffer[seq_index] == '1') {
                count = new_val == 1 ? count + 1 : count;
                buffer.append(1, new_val + '0');
            } else {
                if (buffer.size() + 2 > n) {
                    count = new_val == 1 ? count + 1 : count;
                    buffer.append(1, new_val + '0');
                } else {
                    count = new_val == 1 ? count + 2 : count;
                    buffer.append(2, new_val + '0');
                }
            }
            ++seq_index;
        }
        
        return count;
    }
};

