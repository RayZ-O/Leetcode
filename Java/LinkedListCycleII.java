// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// Note: Do not modify the linked list.

public class LinkedListCycleII {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        ListNode t = null;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (slow == fast) {
                t = slow;
                break;
            }
        }
        if (t == null) {
            return null;
        }
        while (t != head) {
            head = head.next;
            t = t.next;
        }
        return t;
    }
}
