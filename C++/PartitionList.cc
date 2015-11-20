// Given a linked list and a value x, partition it such that all nodes
// less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each
// of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode new_head(0);
        ListNode nl_head(0);
        ListNode* cur_l = &new_head;
        ListNode* cur_nl = &nl_head;
        while (head) {
            if (head->val < x) {
                cur_l->next = head;
                cur_l = head;
            } else {
                cur_nl->next = head;
                cur_nl = head;
            }
            head = head->next;
        }
        cur_nl->next = nullptr;
        cur_l->next = nl_head.next;
        return new_head.next;
    }
};
