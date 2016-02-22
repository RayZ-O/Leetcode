// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

public class RemoveDuplicatesFromSortedList {
    public ListNode deleteDuplicatesUntil(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        head.next = deleteDuplicatesUntil(head.next);
        return head.next.val == head.val ? head.next : head;
    }

    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;
        while (cur != null) {
            while (cur.next != null && cur.next.val == cur.val) {
                cur.next = cur.next.next;
            }
            cur = cur.next;
        }
        return head;
    }
}
