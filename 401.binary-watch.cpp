/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (45.10%)
 * Total Accepted:    60.9K
 * Total Submissions: 135K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */
class Solution {
public:
    void GenerateNumber(int num, int num_on, int left_bit, set<int>& result) {
        if (num_on == 0) {
            result.insert(num);
            return;
        }

        if (num_on == left_bit) {
            num = (num << num_on) + ((1 << num_on) - 1);
            result.insert(num);
            return;
        }

        GenerateNumber(num << 1, num_on, left_bit - 1, result);
        GenerateNumber((num << 1) + 1, num_on - 1, left_bit -1, result);
    }

    void GenerateStrAndCombineNum(const vector<int>& hours, const vector<int>& mins, vector<string>& result) {
        for (auto hour : hours) {
            if (hour > 11) {
                continue;
            }
            for (auto min : mins) {
                if (minite > 59) {
                    continue;
                }
                string buff = to_string(hour) + to_string(minite);
                result.push_back(buff);
            }
        }
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int i = 0; i < num && i <= 3; ++i) {
            set<int> hours;
            GenerateNumber(0, i, 4, hours);
            set<int> mins;
            GenerateNumber(0, n - i, 6, mins);

            GenerateStrAndCombineNum(hour, minite, result);
        }

        return result;
    }
};

