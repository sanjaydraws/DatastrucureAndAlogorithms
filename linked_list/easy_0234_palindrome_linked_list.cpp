#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
// Time Complexity	O(n)	One pass to find middle, one to reverse, one to compare
// Space Complexity	O(1)	All operations done in-place, no extra array or recursion
    bool isPalindrome(ListNode* head) {
        // Edge case: empty list or single node is always a palindrome
        if (!head || !head->next) return true;

        // Step 1: Find the middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next; // store next node
            curr->next = prev;               // reverse pointer
            prev = curr;                     // move prev
            curr = nextNode;                 // move curr
        }

        // Step 3: Compare first half and reversed second half
        ListNode* first = head;
        ListNode* second = prev; // head of reversed half
        while (second) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true; // all matched
    }
};


int main() {
    // Example: 1 → 2 → 2 → 1 (palindrome)
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution sol;
    bool result = sol.isPalindrome(n1);
    cout << (result ? "Palindrome" : "Not Palindrome") << endl;

    // Free memory
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}
wha