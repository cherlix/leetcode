/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 *
 * https://leetcode.com/problems/linked-list-random-node/description/
 *
 * algorithms
 * Medium (48.87%)
 * Total Accepted:    50.5K
 * Total Submissions: 103.3K
 * Testcase Example:  '["Solution","getRandom"]\n[[[1,2,3]],[]]'
 *
 * Given a singly linked list, return a random node's value from the linked
 * list. Each node must have the same probability of being chosen.
 * 
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you?
 * Could you solve this efficiently without using extra space?
 * 
 * 
 * Example:
 * 
 * // Init a singly linked list [1,2,3].
 * ListNode head = new ListNode(1);
 * head.next = new ListNode(2);
 * head.next.next = new ListNode(3);
 * Solution solution = new Solution(head);
 * 
 * // getRandom() should return either 1, 2, or 3 randomly. Each element should
 * have equal probability of returning.
 * solution.getRandom();
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : seed((random_device())()) {
        m_head = head;


    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i = 0;
        ListNode* node = m_head;
        ListNode* selected_node = m_head;
        while (node) {
            if (getRandomRange(1, i) == 1) {
                selected_node = node;
            }
            node = node->next;
            ++i;
        }

        return selected_node->val;
    }

private:
    int getRandomRange(int a, int b) {
        return uniform_int_distribution<int>{a, b}(seed);
    }

    default_random_engine seed;
    ListNode* m_head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// 1. Why the possibility is correct, look for the proof.
// 2. Remeber how to get random number from range.

