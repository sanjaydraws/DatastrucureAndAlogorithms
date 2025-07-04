//https://leetcode.com/problems/reverse-linked-list/
//206. Reverse Linked List
// Easy
// Given the head of a singly linked list, reverse the list, and return the reversed list.

#include <iostream>
using namespace std;

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // store next node
            curr->next = prev;               // reverse pointer
            prev = curr;                     // move prev
            curr = nextNode;                 // move curr
        }

        return prev; // new head
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from array
ListNode* createList(const initializer_list<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : vals) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    // Create linked list from vector: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createList({1, 2, 3, 4, 5});
    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}
