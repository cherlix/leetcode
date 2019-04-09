/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (37.69%)
 * Total Accepted:    50.2K
 * Total Submissions: 133.3K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * ⁠Length of the given array is positive and will not exceed 10^4
 * ⁠Absolute value of elements in the array and x will not exceed 10^4
 * 
 * 
 * 
 * 
 * 
 * 
 * UPDATE (2017/9/19):
 * The arr parameter had been changed to an array of integers (instead of a
 * list of integers). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
public:
    int findLowerBound(const vector<int>& arr, int x) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m] < x) {
                l = m + 1;
            } else if (arr[m] > x) {
                r = m - 1;
            } else {
                r = m;
            }
        }
        return l;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = findLowerBound(arr, x);
        
        vector<int> result;
        int backward_index = index;
        int forward_index = index + 1;

        while (k > 0 && back_ward_index >= 0 && forward_index < arr.size()) {
            if (abs(arr[backward_index] - k) <= abs(arr[forward_index] - k)) {
                result.push_back(arr[backward_index--]);
            } else {
                result.push_back(arr[forward_index++]);
            }
            --k;
        }

        if (k > 0) {
            if (backward_index >= 0) {
                while (backward_index >= 0 && k > 0) {
                    result.push_back(arr[backward_index--]);
                    --k;
                }
            } else {
                while (forward_index < arr.size() && k > 0) {
                    result.push_back(arr[forward_index++]);
                    --k;
                }
            }
        }

        return result;
    }
};

