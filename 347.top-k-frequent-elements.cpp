/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (54.08%)
 * Total Accepted:    190.6K
 * Total Submissions: 352.1K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
class Solution {
public:
    struct CmpFn {
        bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second < p2.second;
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> memo;
        for (int i : nums) {
            ++memo[i];
        }

        priority_queue<pair<int,int>, vector<pair<int, int>, CmpFn> queue; 
        for (auto it : memo) {
            if (queue.size() < k) {
                queue.push({it.first, it.second});
            } else if (queue.top().second < it.second) {
                queue.pop();
                queue.push({it.first, it.second});
            }
        }
        vector<int> result;
        while (queue.size() != 0) {
            result.push(queue.top().first);
            queue.pop();
        }
        return result;
    }
};

