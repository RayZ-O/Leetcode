// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values
// in the list, only nodes itself can be changed.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* new_head = head->next;
        ListNode* cur = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while (cur) {
            if (!cur->next)
                break;
            next = cur->next;
            ListNode* next_cur = next->next;
            next->next = cur;
            if (prev)
                prev->next = next;
            prev = cur;
            cur = next_cur;
        }
        if (prev)
            prev->next = cur;
        return new_head;
    }
};
