// Given a singly linked list where elements are sorted in ascending order, convert it to a height
// balanced BST.

public class ConvertSortedListToBinarySearchTree {
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode h = new ListNode(0);
        h.next = head;
        ListNode slow = h;
        ListNode fast = head.next;
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
            if (fast != null) {
                fast = fast.next;
            }

        }
        ListNode next = slow.next;
        slow.next = null;
        TreeNode root = new TreeNode(next.val);
        root.left = sortedListToBST(h.next);
        root.right = sortedListToBST(next.next);
        return root;
    }
}
