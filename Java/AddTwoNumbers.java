// You are given two linked lists representing two non-negative numbers. The digits are stored
// in reverse order and each of their nodes contain a single digit. Add the two numbers and return
// it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = new ListNode(0);
        ListNode cur = head;
        while (l1 != null || l2 != null || carry != 0) {
            int l = 0, r = 0;
            if (l1 != null) {
                l = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                r = l2.val;
                l2 = l2.next;
            }
            int val = l + r + carry;
            cur.next = new ListNode(val % 10);
            carry = val / 10;
            cur = cur.next;
        }
        return head.next;
    }
}
