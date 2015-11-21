// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

class Solution {
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        while (node) {
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }
    ListNode* insert(ListNode* node, ListNode* next) {
        if (!node->next) {
            node->next = next;
            next->next = nullptr;
        } else {
            next->next = node->next;
            node->next = next;
        }
        return next->next;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *rev_half = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* node = head;
        while (rev_half) {
            ListNode* temp = rev_half->next;
            node = insert(node, rev_half);
            rev_half = temp;
        }
    }
};
