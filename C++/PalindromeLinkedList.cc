// Given a singly linked list, determine if it is a palindrome.

// Follow up:
// Could you do it in O(n) time and O(1) space?

class Solution {
    ListNode* reverseList(ListNode* head, ListNode* next) {
        if (!next) return head;
        else {
            ListNode* temp = next->next;
            next->next = head;
            return reverseList(next, temp);
        }
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        int cnt = 1;
        ListNode* node = head;
        while (node->next) {
            cnt++;
            node = node->next;
        }
        node = head;
        for(int i = 1; i <= cnt/2; i++) node = node->next;
        ListNode* mid = node;
        ListNode* newHead = reverseList(mid, mid->next);
        mid->next = nullptr;
        while(head != newHead) {
            if (head->val != newHead->val) return false;
            if (head->next == newHead) break; 
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};
