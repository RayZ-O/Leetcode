// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// You may not alter the values in the nodes, only nodes itself may be changed.

// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

public class ReverseNodesInKGroup {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode h = new ListNode(0);
        h.next = head;
        ListNode cur = h;
        while (head != null) {
            int n = k;
            while (head != null && n-- > 0) {
                head = head.next;
            }
            if (n > 0) {
                break;
            }
            ListNode e = cur.next;
            cur.next = reverse(cur.next, head);
            cur = e;
            head = e.next;
        }
        return h.next;
    }

    ListNode reverse(ListNode head, ListNode end) {
        ListNode prev = end;
        while (head != end) {
            ListNode t = head.next;
            head.next = prev;
            prev = head;
            head = t;
        }
        return prev;
    }
}
