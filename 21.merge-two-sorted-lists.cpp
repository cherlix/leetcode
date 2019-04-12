/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.53%)
 * Total Accepted:    548.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* move = l1->val <= l2->val ? l1 : l2;
        ListNode* indicator = l1->val <= l2->val ? l2 : l1;
        while (move && indicator) {
            if (move->next == nullptr || move->next->val > indicator->val) {
                ListNode* temp = move->next;
                move->next = indicator;
                move = indicator;
                indicator = temp;
            } else {
                move = move->next;
            }
        }
        
        return l1->val <= l2->val ? l1 : l2;
    }
};

