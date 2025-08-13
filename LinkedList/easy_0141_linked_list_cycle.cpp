https://leetcode.com/problems/linked-list-cycle/description/
// LeetCode 141. Linked List Cycle

// Floyd’s Cycle Detection Algorithm (Tortoise & Hare)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;              // 1 step
            fast = fast->next->next;        // 2 steps

            if (slow == fast) return true;  // cycle detected
        }

        return false; // reached end
    }
};
