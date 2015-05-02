
// You are given two linked lists representing two non-negative numbers. 
// The digits are stored in reverse order and each of their nodes contain a 
// single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	 void buildNode(int sum, int &carry, ListNode *current) {
    	if (sum >= 10) {
    		current->next = new ListNode(sum-10);
    		carry = 1;
    	} else {
    		current->next = new ListNode(sum);
    		carry = 0;
    	}
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        // both number dosen't reach the end
        while (l1 && l2) {
        	int sum = l1->val + l2->val + carry;
        	buildNode(sum, carry, current);
        	l1 = l1->next;
        	l2 = l2->next;
        	current = current->next;
        }
        // l2 reach the end first
        while (l1) {
        	int sum = l1->val + carry;
        	buildNode(sum, carry, current);
        	l1 = l1->next;
        	current = current->next;
        } 
        // l1 reach the end first
        while (l2) {
        	int sum = l2->val + carry;
        	buildNode(sum, carry, current);
        	l2 = l2->next;
        	current = current->next;
        }
        // there may be one more bit at highest position
        if (carry) {
        	current->next = new ListNode(1);
        }
        ListNode *result = head->next;
        head->next = nullptr;
        // avoid memory leak
        delete head;
        return result;
    }
};