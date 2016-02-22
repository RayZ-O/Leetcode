public class RemoveDuplicatesFromSortedListII {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode cur = head;
        while (cur.next != null && cur.next.val == cur.val) {
            cur = cur.next;
        }
        if (cur != head) {
            return deleteDuplicates(cur.next);
        } else {
            head.next = deleteDuplicates(head.next);
            return head;
        }
    }

    public ListNode deleteDuplicates(ListNode head) {
        ListNode h = new ListNode(0);
        ListNode cur = h;
        while (head != null) {
            if (head.next == null || head.next.val != head.val) {
                cur.next = head;
                cur = cur.next;
            } else {
                while (head.next != null && head.next.val == head.val) {
                    head = head.next;
                }
            }
            head = head.next;
        }
        cur.next = null;
        return h.next;
    }
}
