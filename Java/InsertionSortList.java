// Sort a linked list using insertion sort.

public class InsertionSortList {
    public ListNode insertionSortList(ListNode head) {
        ListNode nh = new ListNode(0);
        ListNode pre = nh;
        ListNode cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            while (pre.next != null && cur.val > pre.next.val) {
                pre = pre.next;
            }
            cur.next = pre.next;
            pre.next = cur;
            cur = next;
            pre = nh;
        }
        return nh.next;
    }
}
