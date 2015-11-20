// Given a linked list, reverse the nodes of a linked list k at a time and
// return its modified list.

// If the number of nodes is not a multiple of k then left-out nodes in the
// end should remain as it is.

// You may not alter the values in the nodes, only nodes itself may be changed.

// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1)
            return head;
        ListNode newHead(0);
        newHead.next = head;
        ListNode* last_end = &newHead;
        while (true) {
            int i = 1;
            ListNode* group_beg = head;
            while (head && i < k) {
                head = head->next;
                i++;
            }
            if (i != k || !head) {
                break;
            }
            last_end->next = reverseList(group_beg, head);
            last_end = group_beg;
            head = group_beg->next;
        }
        return newHead.next;
    }
};

