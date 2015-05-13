// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.

// Note:
// Given n will always be valid.
// Try to do this in one pass. 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n < 1) {
            return head;
        }
        ListNode *fast = head;
        int count = 0;
        while (count < n && fast) {
            fast = fast->next;
            count++;
        }
        ListNode *slow = head;
        if (n == 1) {
            if (!fast) {
                delete head;
                head = nullptr;
            } else {
                fast = fast->next;
                while (fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                delete slow->next;
                slow->next = nullptr;
            }            
        } else if (fast || count == n) {
            while (fast) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->val = slow->next->val;
            ListNode *temp = slow->next;
            slow->next = slow->next->next;
            delete temp;  
        }
        return head;
    }
};