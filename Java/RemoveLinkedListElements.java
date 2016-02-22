// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

class RemoveLinkedListElements {
	public ListNode removeElementsUntil(ListNode head, int val) {
		if (head == null) {
			return null;
		}
		head.next = removeElementsUntil(head.next, val);
		return head.val == val ? head.next : head;
    }

    public ListNode removeElements(ListNode head, int val) {
		ListNode n = new ListNode(0);
		n.next = head;
		ListNode cur = n;
		while (cur != null) {
			while (cur.next != null && cur.next.val == val) {
				cur.next = cur.next.next;
			}
			cur = cur.next;
		}
		return n.next;
    }
}
