// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/



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
// Metric	Complexity
// Time Complexity	O(n)
// Space Complexity	O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Skip the duplicate node
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; //  good in real use
            } else {
                current = current->next; // move forward
            }
        }

        return head;
    }
};
