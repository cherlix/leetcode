/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (50.02%)
 * Total Accepted:    55.7K
 * Total Submissions: 111.4K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note: There are at least two nodes in this BST.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorderTraverse(TreeNode* root, vector<int>& sorted) {
        if (root->left) {
            inorderTraverse(root->left, sorted);
        }
        sorted.push_back(root->val);
        if (root->right) {
            inorderTraverse(root->right, sorted);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> sorted;
        inorderTraverse(root, sorted);

        int min_diff = sorted[1] - sorted[0];
        for (int i = 2; i < sorted.size(); ++i) {
            min_diff = min(sorted[i] - sorted[i - 1], min_diff);
        }

        return min_diff;
    }
};

