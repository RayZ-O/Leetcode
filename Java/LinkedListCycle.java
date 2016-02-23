// Given a linked list, determine if it has a cycle in it.

public class LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
            if (fast == null) {
                break;
            }
            fast = fast.next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
}
