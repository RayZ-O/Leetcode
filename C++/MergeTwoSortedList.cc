// Merge two sorted linked lists and return it as a new list. The new list should be made 
// by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
	    return l2;
        } else if (!l2) {
	    return l1;
        }
	// traverser
	ListNode *p1 = l1;
	ListNode *p2 = l2;
	// head of unsorted portion
	ListNode *h1 = l1;
	ListNode *h2 = l2;
	ListNode *head = new ListNode(0);
	ListNode *sorted = head;    // tail of sorted portion
	ListNode *current = head;   // previous node of current traverser
	while (p1 && p2) {
	    if (p1->val < p2->val) {
	        do {
		    current = p1;
		    p1 = p1->next;
		} while (p1 && p1->val < p2->val);
		sorted->next = h1;
		h1 = p1;
	    } else {
                do {
		    current = p2;
		    p2 = p2->next;
		} while (p2 && p1->val >= p2->val);	
		sorted->next = h2;
		h2 = p2;
	    }			
	    sorted = current;
	}
	if (!p1) {
	    sorted->next = p2;
	} else if (!p2) {
	    sorted->next = p1;
	}
	ListNode *result = head->next;
	head->next = nullptr;
	delete head;
	return result;
    }
};
