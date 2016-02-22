// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list,
// only nodes itself can be changed.

public class SwapNodesInPairs {
    public ListNode swapPairsUntil(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode h = head.next;
        ListNode n = swapPairsUntil(h.next);
        h.next = head;
        head.next = n;
        return h;
    }

    public ListNode swapPairs(ListNode head) {
        ListNode h = new ListNode(0);
        ListNode prev = h;
        while (head != null) {
            if (head.next == null) {
                prev.next = head;
                break;
            } else {
                prev.next = head.next;
                ListNode temp = head.next.next;
                head.next.next = head;
                head.next = null;
                prev = head;
                head = temp;
            }
        }
        return h.next;
    }
}
