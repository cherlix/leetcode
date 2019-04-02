/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (39.92%)
 * Total Accepted:    168.9K
 * Total Submissions: 423.1K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        list<TreeNode*> lst;
        lst.push_back(root);
        while (!lst.empty()) {
            auto node = lst.front();
            lst.pop_front();
            if (node->left) {
                lst.push_back(node->left);
                result += to_string(node->val) + ",";
            } else {
                result += "null,";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        auto index = 0;
        auto end_index = data.find(',', index);
        string ss = data.substr(index, end_index);
        int value = stoi(ss);
        TreeNode* root = new TreeNode(value);
        index = end_index + 1;

        list<TreeNode*> lst;
        lst.push_back(root);
        
        while (index < data.size()) {
            TreeNode* node = lst.front();
            lst.pop_front();
            
            end_index = data.find(',', index);
            ss = data.substr(index, end_index);
            if (ss == "null") {
                node->left = nullptr;
            } else {
                node->left = new TreeNode(stoi(ss));
                lst.push_back(node->left);
            }
            index = end_index + 1;
            
            end_index = data.find(',', index);
            ss = data.substr(index, end_index);
            if (ss == "null") {
                node->right = nullptr;
            } else {
                node->right = new TreeNode(stoi(ss));
                lst.push_back(node->right);
            }
            index = end_index + 1;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

