/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (59.85%)
 * Total Accepted:    481.3K
 * Total Submissions: 804K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its depth = 3.
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
    int maxDepthTraversal(TreeNode* root, int depth) {
        int max_depth = depth;
        if (root->left) {
            max_depth = max(maxDepthTraversal(root->left, depth + 1), max_depth);
        }

        if (root->right) {
            max_depth = max(maxDepthTraversal(root->right, depth + 1), max_depth);
        }

        return max_depth;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return maxDepthTraversal(root, 1);
    }
};

