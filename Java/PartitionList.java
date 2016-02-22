// Given a linked list and a value x, partition it such that all nodes less than x come before nodes
// greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

public class PartitionList {
    public ListNode partition(ListNode head, int x) {
        ListNode left = new ListNode(0);
        ListNode right = new ListNode(0);
        ListNode l = left, r = right;
        while (head != null) {
            if (head.val < x) {
                l.next = head;
                l = l.next;
            } else {
                r.next = head;
                r = r.next;
            }
            head = head.next;
        }
        l.next = right.next;
        r.next = null;
        return left.next;
    }
}
