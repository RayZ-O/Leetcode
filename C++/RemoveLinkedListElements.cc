// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5 

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* cur = head;
        ListNode* prev = newHead;
        while (cur) {
        	if (cur->val == val) {
        		prev->next = cur->next;
        		delete cur;     		
        	} else {
        		prev = cur;
        	}
        	cur = cur->next;
        }
        ListNode* result = newHead->next;
        delete newHead;
        return result;
    }
};