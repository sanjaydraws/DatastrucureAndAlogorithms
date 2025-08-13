// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// 19. Remove Nth Node From End of List

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Time Complexity	O(n)	
   // Space Complexity	O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Create a dummy node before head to handle edge cases like removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Initialize two pointers - both starting from the dummy node
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 3: Move fast pointer 'n + 1' steps ahead
        // Why n+1? So that slow ends up just before the node we want to delete
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Step 4: Move both fast and slow together until fast reaches the end
        // Now, slow will be right before the node we want to remove
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5: Skip the target node
        // slow->next is the node to delete; we unlink it from the list
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;

        // Step 6: Free the memory of the deleted node (good practice in C++)
        delete toDelete;

        // Step 7: Store the new head (could be different if head was deleted)
        ListNode* newHead = dummy->next;

        // Step 8: Free the dummy node
        delete dummy;

        // Step 9: Return the actual new head of the list
        return newHead;
    }
};
