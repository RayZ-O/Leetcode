// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || 0 >= k)
            return head;
        int count = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && count < k) {
            fast = fast->next;
            count++;
        }
        ListNode* newHead = nullptr;
        if (fast) {
            while (fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
            newHead = slow->next;
            fast->next = head;
            slow->next = nullptr;
        } else {
            newHead = rotateRight(head, k % count);
        }
        return newHead;
    }
};
