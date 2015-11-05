// Write a program to find the node at which the intersection of two singly linked lists begins.

// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3

// begin to intersect at node c1.

// Notes:

//     If the two linked lists have no intersection at all, return null.
//     The linked lists must retain their original structure after the function returns.
//     You may assume there are no cycles anywhere in the entire linked structure.
//     Your code should preferably run in O(n) time and use only O(1) memory.

class Solution {
    ListNode* countNodes(ListNode* head, int& count) {
         while (head->next) {
            ++count;
            head = head->next;
        }
        return head;
    }
    ListNode* rightJustified(ListNode* head, int diff) {
         while (diff > 0) {
            --diff;
            head = head->next;
        }
        return head;
    }
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        int countA = 1;
        int countB = 1;
        if (countNodes(headA, countA) != countNodes(headB, countB)) {
            return nullptr;
        }
        int diff = countA - countB;
        ListNode* p = headA;
        ListNode* q = headB;
        if (diff >= 0) {
            p = rightJustified(headA, diff);
        } else {
            diff = -diff;
            q = rightJustified(headB, diff);
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
