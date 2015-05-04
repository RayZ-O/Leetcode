// Sort a linked list using insertion sort.

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *sorted = head;
        ListNode *current = head->next;
        ListNode *temp;
        while (current) {
            if (current->val >= sorted->val) {
                current = current->next;
                sorted = sorted->next;
            } else {
                if (current->val < head->val) {
                    temp = current->next;
                    current->next = head;
                    head = current;
                    sorted->next = temp;
                } else {
                    ListNode *runner = head;
                    while (runner != sorted) {
                       if (runner->next->val > current->val) {
                            temp = current->next;
                            current->next = runner->next;
                            runner->next = current;
                            sorted->next = temp;
                            break;
                       } else {
                            runner = runner->next;
                       }
                    }
                }
                current = temp;
            }
        }
        return head;
    }
};