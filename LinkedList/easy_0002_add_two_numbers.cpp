// https://leetcode.com/problems/add-two-numbers/description/

// 2. Add Two Numbers

/* 
You are given two non-empty linked lists representing 
two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit.
 Add the two numbers and return the sum as a linked list.
 */

/*
l1 = [2,4,3]
l2 = [5,6,4]

Explanation:
342 + 465 = 807

Output
[7,0,8]
*/
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify list construction (acts as a placeholder head)
        ListNode dummy;

        // Pointer to build the result list
        ListNode* curr = &dummy;

        // To store carry during addition
        int carry = 0;

        // Traverse both lists until both are null and no carry remains
        while (l1 || l2 || carry) {
            int sum = carry;

            // Add value from l1 if it exists
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from l2 if it exists
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry for next iteration
            carry = sum / 10;

            // Create a new node with the digit part (unit place)
            curr->next = new ListNode(sum % 10);

            // Move the pointer to the new node
            curr = curr->next;
        }

        // The result starts from dummy.next (skip dummy node)
        return dummy.next;
    }
};
