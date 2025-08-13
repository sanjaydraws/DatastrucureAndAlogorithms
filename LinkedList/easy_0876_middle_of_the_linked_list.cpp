// https://leetcode.com/problems/middle-of-the-linked-list/description/

// 876. Middle of the Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
//Two Pointers (Tortoise and Hare) approach.
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps
        }

        return slow; // slow is at the middle
    }
};
