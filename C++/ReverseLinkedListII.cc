// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

class Solution {
    ListNode* reverseList(ListNode* beg, ListNode* end) {
        ListNode* prev = end->next;
        while (beg != end) {
            ListNode* temp = beg->next;
            beg->next = prev;
            prev = beg;
            beg = temp;
        }
        end->next = prev;
        return end;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode h(0);
        h.next = head;
        ListNode* beg = &h;
        ListNode* end = &h;
        int count = 1;
        while (count <= n) {
            if (count < m)
                beg = beg->next;
            end = end->next;
            count++;
        }
        beg->next = reverseList(beg->next, end);
        return h.next;
    }
};
