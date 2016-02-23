// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

public class ReverseLinkedListII {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode h = new ListNode(0);
        h.next = head;
        ListNode b = h;
        ListNode e = head;
        while (--n > 0) {
            if (--m > 0) {
                b = b.next;
            }
            e = e.next;
        }
        ListNode s = e.next;
        ListNode t = b.next;
        b.next = reverseList(b.next, e);
        t.next = s;
        return h.next;
    }

    ListNode reverseList(ListNode head, ListNode end) {
        if (head == end) {
            return head;
        }
        ListNode n = reverseList(head.next, end);
        head.next.next = head;
        head.next = null;
        return n;
    }
}
