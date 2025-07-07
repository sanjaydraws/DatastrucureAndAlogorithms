
//https://leetcode.com/problems/intersection-of-two-linked-lists/
// 160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If either list is empty, no intersection
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        // Keep looping until they meet or both hit nullptr
        while (pA != pB) {
            // Move to next node or switch to other list's head
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        // Either both are null or both at intersection
        return pA;
    }
};
