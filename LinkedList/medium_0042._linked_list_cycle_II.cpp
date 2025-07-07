// https://leetcode.com/problems/linked-list-cycle-ii/
//142. Linked List Cycle II


#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Time Complexity: O(N)
// Space: Constant → O(1)
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // 🔹 Step 1: Detect if a cycle exists using Floyd’s algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // move 1 step
            fast = fast->next->next;   // move 2 steps

            // 🎯 If slow and fast meet, cycle is confirmed
            if (slow == fast) {
                break;
            }
        }

        // 🔸 No cycle if fast reached end
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // 🔹 Step 2: Find the entry point of the cycle
        ListNode* entry = head;

        // Move entry and slow 1 step at a time
        while (entry != slow) {
            entry = entry->next;
            slow = slow->next;
        }

        // 🎉 They meet at the cycle start
        return entry;
    }
};
