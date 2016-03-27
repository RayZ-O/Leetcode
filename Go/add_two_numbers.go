// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse 
// order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	carry := 0;
	head := new(ListNode);
	cur := head;
	for l1 != nil || l2 != nil || carry != 0 {
		n1 := 0;
		n2 := 0;
		if l1 != nil {
			n1 = l1.Val;
			l1 = l1.Next;
		}
		if l2 != nil {
			n2 = l2.Val;
			l2 = l2.Next;
		}
		num := n1 + n2 + carry;
		carry = num / 10;
		cur.Next = &ListNode{Val:num%10, Next:nil};
		cur = cur.Next;
	}
	return head.Next;
}
