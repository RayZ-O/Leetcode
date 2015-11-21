// Given a singly linked list where elements are sorted in ascending order,
// convert it to a height balanced BST.

class Solution {
    // precondition: first has more than 1 node
    ListNode* getMid(ListNode* first, ListNode* &second) {
        ListNode* fast = first->next->next;
        ListNode* slow = first;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        second = mid->next;
        return mid;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);
        ListNode* second = nullptr;
        ListNode* mid = getMid(head, second);
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(second);
        return root;
    }
};
