/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (41.07%)
 * Total Accepted:    208.6K
 * Total Submissions: 506.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bool revert = false;
        list<TreeNode*> l;
        l.push_back(root);
        while (!l.empty()) {
            vector<TreeNode*> vec;
            while (!l.empty()) {
                vec.push_back(l.front());
                l.pop_front();
            }
            for (auto node : vec) {
                if (node->left) {
                    l.push_back(node->left);
                }
                if (node->right) {
                    l.push_back(node->right);
                }
            }
            vector<int> r;
            int i = revert ? vec.size() - 1 : 0;
            int size = 0;
            while (size++ < vec.size()) {
                r.push_back(vec[i]->val);
                if (revert) {
                    --i;
                } else {
                    ++i;
                }
            }
            result.emplace_back(r);
            revert = !revert;
        }
        return result;
    }
};

