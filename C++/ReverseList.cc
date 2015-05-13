// Reverse a singly linked list.

// iterative
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		} 
		ListNode *p = head;	
		ListNode *son = head->next;
		ListNode *grandSon = son;
		while (grandSon) {
			grandSon = son->next;
			son->next = p;
			p = son;
			son = grandSon;
			
		}
		head->next = nullptr;
		return p;
	}
};

// recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (!head || !head->next) {
    		return head;
     	} 
     	ListNode *rhead = reverseList(head->next);
     	head->next->next = head;
     	head->next = nullptr;
     	return rhead;
    }
};