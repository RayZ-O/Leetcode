// Write a program to find the node at which the intersection of two singly linked lists begins.

// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3

// begin to intersect at node c1.

// Notes:

//     If the two linked lists have no intersection at all, return null.
//     The linked lists must retain their original structure after the function returns.
//     You may assume there are no cycles anywhere in the entire linked structure.
//     Your code should preferably run in O(n) time and use only O(1) memory.

public class IntersectionOfTwoLinkedLists {
    public class ListInfo {
        int length;
        ListNode lastNode;
        ListInfo(int length, ListNode lastNode) {
            this.length = length;
            this.lastNode = lastNode;
        }
    }

    public ListInfo getListInfo(ListNode head) {
        int length = 0;
        while (head.next != null) {
            head = head.next;
            length++;
        }
        return new ListInfo(length, head);
    }

    public ListNode getIntersectionNode(ListNode headLong, ListNode headShort, int diff) {
        for (int i = 0; i < diff; i++)
            headLong = headLong.next;
        while (headLong != headShort) {
            headLong = headLong.next;
            headShort = headShort.next;
        }
        return headLong;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;
        ListInfo listInfoA = getListInfo(headA);
        ListInfo listInfoB = getListInfo(headB);
        if (listInfoA.lastNode != listInfoB.lastNode)
            return null;
        int diff = listInfoA.length - listInfoB.length;
        if (diff >= 0)
            return getIntersectionNode(headA, headB, diff);
        else
            return getIntersectionNode(headB, headA, -diff);
    }
}
