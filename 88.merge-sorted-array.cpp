/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (35.29%)
 * Total Accepted:    347.5K
 * Total Submissions: 984.6K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int write_index = m + n - 1;
        int index_1 = m - 1;
        int index_2 = n - 1;
        while (index_1 >= 0 && index_2 >= 0) {
            if (nums1[index_1] > nums2[index_2]) {
                nums1[write_index++] = nums1[index_1--];
            } else {
                nums1[write_index++] = nums2[index_2--];
            }
        }
        while (index_2 >= 0) {
            nums1[write_index++] = nums2[index_2--];
        }
    }
};

