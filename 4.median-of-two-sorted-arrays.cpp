/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.76%)
 * Total Accepted:    398.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 && nums2.size() == 0) {
            return 0.0;
        }

        vector<int>* temp = nullptr;
        if (nums1.size() == 0) {
            temp = &nums2;
        } else if (nums2.size() == 0) {
            temp = &nums1;
        }

        if (temp) {
            int middle = temp->size() / 2;
            return (temp->size() % 2) == 0 ? ((*temp)[middle] + (*temp)[middle + 1]) / 2.0 : (*temp)[middle];
        }

        vector<int>* smaller = nullptr;
        vector<int>* bigger = nullptr;
        if (nums1[nums1.size() - 1] <= nums2[0]) {
            smaller = &nums1;
            bigger = &nums2;
        } else if (nums2[nums2.size() - 1] <= nums1[0]) {
            smaller = &nums2;
            bigger = &nums1;
        }

        if (smaller && bigger) {
            int middle = (smaller.size() + bigger.size()) / 2;
            int remainder = (smaller.size() + bigger.size()) % 2;

            if (middle == smaller.size() - 1) {
                return remainder == 0 ? (smaller[middle] + bigger[0]) / 2.0 : smaller[middle];
            } else if (middle < smaller.size() - 1) {
                return remainder == 0 ? (smaller[middle] + smaller[middle + 1]) / 2.0 : smaller[middle];
            } else {
                middle -= smaller.size();
                return remainder == 0 ? (bigger[middle] + bigger[middle + 1]) / 2.0 : bigger[middle];
            }
        }

        int l = 0, r = nums1.size() - 1;
        int index_2 = nums2.size() / 2;
        int last_middle = l + (r - l) / 2;
        while (l < r) {
            int middle = l + (r - l) / 2;
            index_2 += middle - last_middle;
            index_2 = max(0, index_2);
            index_2 = min(nums.size(), )
            if (nums1[middle] == nums2[index_2]) {
                return nums1[middle];
            } else if (nums1[middle] < nums2[index_2]) {
                l = middle + 1;
            } else {
                r = middle - 1;
            }
            last_middle = middle;
        }
    }
};

