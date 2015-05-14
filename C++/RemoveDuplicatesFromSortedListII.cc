// Given a sorted linked list, delete all nodes that have duplicate numbers, 
// leaving only distinct numbers from the original list.

// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3. 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (!head || !head->next) {
    		return head;
    	}       
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        while (head->next && head->val != head->next->val) {
        	prev = head;
        	head = head->next;
        }
        ListNode* base = head;
        ListNode* cur = head->next;
        int val = base->val;
        while (cur) {
        	if(cur->val == val) {
        		delete base;
        		do {
        			ListNode* temp = cur;
        			cur = cur->next;
        			delete temp;
        		} while (cur && cur->val == val);
        		prev->next = cur;
        	} else { 
        		base = cur;
        		val = base->val;
        		cur = cur->next;
        		if (cur && cur->val != base->val) {
        			prev = base;
        		}
        	}
        }
        ListNode *result = newHead->next;
        delete newHead;
        return result;
    }
};