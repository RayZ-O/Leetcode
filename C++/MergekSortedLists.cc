// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.

class Solution {
    class Compare {
    public:
        bool operator() (const ListNode* lhs, const ListNode* rhs) {
          return lhs->val > rhs->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode* cur = &head;
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;
        for (auto l : lists) {
            if (l) min_heap.push(l);
        }
        while (!min_heap.empty()) {
            ListNode* l = min_heap.top();
            cur->next = l;
            min_heap.pop();
            if (l->next) {
                min_heap.push(l->next);
            }
            cur = cur->next;
        }
        return head.next;
    }
};
