// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

public class ReorderList {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        // find middle
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode r = null;
        ListNode h = slow.next;
        // reverse
        while (h != null) {
            ListNode n = h.next;
            h.next = r;
            r = h;
            h = n;
        }
        // merge
        while (r != null) {
            ListNode t = head.next;
            head.next = r;
            head = t;
            t = r.next;
            r.next = head;
            r = t;
        }
        head.next = null;
    }
}
