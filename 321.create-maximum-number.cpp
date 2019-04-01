/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (25.23%)
 * Total Accepted:    29.2K
 * Total Submissions: 115.8K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two. The
 * relative order of the digits from the same array must be preserved. Return
 * an array of the k digits.
 * 
 * Note: You should try to optimize your time and space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * Output:
 * [9, 8, 6, 5, 3]
 * 
 * Example 2:
 * 
 * 
 * Input:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * Output:
 * [6, 7, 6, 0, 4]
 * 
 * Example 3:
 * 
 * 
 * Input:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * Output:
 * [9, 8, 9]
 * 
 */
class Solution {
public:
    struct Key {
        int val;
        int index;

        Key(int _val, int _index) : val(_val), index(_index) {}
    };

    struct CmpFn {
        bool operator(const Key& k1, const Key& k2) {
            return k1.val > k2.val;
        }
    };

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Key, vector<Key>, CmpFn> q;
        for (int i = 0; i < min(k, nums1.size()), ++i) {
            q.push({nums1[i], i});
        }
        if (k > nums1.size()) {
            for (int i = 0; i < min(nums2.size(), k - nums1.size()); ++i) {
                q.push({nums2[i], nums1.size() + i});
            }
        }
        for (int i = k; i < nums1.size(); ++i) {
            if (q.top() < nums1[i]) {
                q.pop();
                q.push({nums1[i], i});
            }
        }
        for (int i = max(0, k - nums1.size()); i < nums2.size(); ++i) {
            if (q.top() < nums2[i]) {
                q.pop();
                q.push({nums2[i], i + nums1.size()});
            }
        }

        vector<Key> buff;
        buff.reserve(k);
        int num1 = 0;
        while(!q.empty()) {
            if (q.top().index < nums1.size()) {
                ++num1;
            }
            buff.emplace_back(q.top());
            q.pop();
        }

        sort(buff.begin(), buff.end(), [](const Key& k1, const Key& k2) {
            return k1.index < k2.index;
        });

        int index1 = 0, index2 = num1;
        vector<int> result;
        result.reserve(k);
        while(index1 == num1 || index2 == buff.size()) {
            if (buff[index1].val > buff[index2].val) {
                result.push_back(buff[index1].val);
                ++index1;
            } else {
                result.push_back(buff[index2].val);
                ++index2;
            }
        }
        if (index1 == num1) {
            for (int i = index2; i < buff.size(); ++i) {
                result.push_back(buff[i]);
            }
        }
        if (index2 == buff.size()) {
            for (int i = index1; i < num1; ++i) {
                result.push_back(buff[i]);
            }
        }

        return result;
    }
};

