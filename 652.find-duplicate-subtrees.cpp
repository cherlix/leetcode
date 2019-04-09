/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (44.79%)
 * Total Accepted:    34.7K
 * Total Submissions: 77.4K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them.
 * 
 * Two trees are duplicate if they have the same structure with same node
 * values.
 * 
 * Example 1: 
 * 
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * 
 * The following are two duplicate subtrees:
 * 
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * 
 * and
 * 
 * 
 * ⁠   4
 * 
 * Therefore, you need to return above trees' root in the form of a list.
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
    string findDupNodeRecursive(TreeNode* root, map<string, int>& memo, vector<TreeNode*>& result) {
        if (root == nullptr) {
            return "#";
        }

        string node_id =  findDupNodeRecursive(root->left, memo, result);
        node_id += ',';
        node_id += findDupNodeRecursive(root->right, memo, result);
        node_id += ',';
        node_id += to_string(root->val);

        if (memo.find(node_id) == memo.end()) {
            memo[node_id] = 1;
        } else if (memo[node_id] == 1) {
            result.push_back(root);
            ++memo[node_id];
        } else {
            ++memo[node_id];
        }

        return node_id;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> memo;
        vector<TreeNode*> result;

        findDupNodeRecursive(root, memo, result);

        return result;
    }
};

