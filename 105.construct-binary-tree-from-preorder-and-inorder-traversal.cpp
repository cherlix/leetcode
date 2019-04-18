/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (40.22%)
 * Total Accepted:    213.2K
 * Total Submissions: 528K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        if (it != inorder.begin()) {
            auto distance = it - inorder.begin();
            vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + distance);
            vector<int> inorder_left(preorder.begin(), preorder.begin() + distance);
            root->left = buildTree(preorder_left, inorder_left);
        }
        if (it != inorder.end() - 1) {
            auto distance = it - inorder.begin();
            vector<int> preorder_right(preorder.begin() + 1 + distance, preorder.end());
            vector<int> inorder_right(preorder.begin() + 1 + distance, preorder.end());
            root->left = buildTree(preorder_right, inorder_right);
        }

        return root;
    }
};

