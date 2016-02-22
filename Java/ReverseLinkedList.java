// Reverse a singly linked list.

public class ReverseLinkedList {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    public ListNode reverseListUntil(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode n = reverseListUntil(head.next);
        head.next.next = head;
        head.next = null;
        return n;
    }
}
