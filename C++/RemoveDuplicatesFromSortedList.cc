// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3. 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (!head || !head->next) {
    		return head;
    	}
        ListNode* cur = head->next;
        ListNode* base = head;
        int val = head->val;
        while (cur) {
        	if(cur->val == val) {
        		do {
        			ListNode* temp = cur;
        			cur = cur->next;
        			delete temp;
        		} while (cur && cur->val == val);
        		base->next = cur;
        	} else {
        		base = cur;
        		val = cur->val;
        		cur = cur->next;
        	}
        }
        return head;
    }
};