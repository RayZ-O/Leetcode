// Given a singly linked list, determine if it is a palindrome.

public class PalindromeLinkedList {
    ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode n = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return n;
    }

    public boolean isPalindrome(ListNode head) {
        int len = 0;
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
            if (fast != null) {
                fast = fast.next;
            }
        }
        ListNode rev = reverseList(slow);
        while (head != null && rev != null) {
            if (head.val != rev.val) {
                return false;
            }
            head = head.next;
            rev = rev.next;
        }
        return true;
    }
}
