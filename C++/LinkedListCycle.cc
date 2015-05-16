// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space? 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fase->next) {
        	if (fast == slow) {
        		return true;
        	}
        	fast = fast->next->next;
        	slow = slow->next;
        }
        return false;
    }
};