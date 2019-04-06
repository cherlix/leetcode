/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (48.04%)
 * Total Accepted:    40.7K
 * Total Submissions: 84.7K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */
class Solution {
public:
    struct Element {
        int val;
        int index;
        
        Element(int _val, int _index) : val(_val), index(_index) {}
    };

    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<Element> elements;
        elements.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            elements.emplace_back(Element(nums[i], i));
        }

        sort(elements.begin(), elements.end(), [] (const Element& a, const Element& b) {
            return a.val > b.val;
        });

        vector<string> result(nums.size(), string());
        for (int i = 0; i < elements.size(); ++i) {
            result[element.index]
            if (i == 0) {
                result[element.index] = "Gold Medal";
            } else if (i == 1) {
                result[element.index] = "Silver Medal";
            } else if (i == 2) {
                result[element.index] = "Bronze Medal";
            } else {
                result[element.index] = to_string(i + 1);
            }
        }

        return result;
    }
};

