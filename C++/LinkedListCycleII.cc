// Given a linked list, return the node where the cycle begins.
// If there is no cycle, return null.

// Note: Do not modify the linked list.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        bool has_cycle = false;
        while (ptr1 && ptr1->next) {
            ptr1 = ptr1->next->next;
            ptr2 = ptr2->next;
            if (ptr1 == ptr2) {
                has_cycle = true;
                break;
            }
        }
        if (has_cycle) {
            ptr1 = head;
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
        return nullptr;
    }
};
