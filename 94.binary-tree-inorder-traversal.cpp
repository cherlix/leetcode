/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (55.83%)
 * Total Accepted:    436.2K
 * Total Submissions: 780.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    void inorderTraversalRecursive(TreeNode* root, vector<int>& result) {
        if (root->left) {
            inorderTraversalRecursive(root, result);
        }

        result.push_back(root->val);

        if (root->right) {
            inorderTraversalRecursive(root, result);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != nullptr) {
            inorderTraversalRecursive(root, result);
        }
        return result;
    }
};

