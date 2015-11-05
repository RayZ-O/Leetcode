#!/usr/bin/env python
# Write a program to find the node at which the intersection of two singly linked lists begins.

# For example, the following two linked lists:

# A:          a1 → a2
#                    ↘
#                      c1 → c2 → c3
#                    ↗
# B:     b1 → b2 → b3

# begin to intersect at node c1.

# Notes:

#     If the two linked lists have no intersection at all, return null.
#     The linked lists must retain their original structure after the function returns.
#     You may assume there are no cycles anywhere in the entire linked structure.
#     Your code should preferably run in O(n) time and use only O(1) memory.

class Solution(object):
    def get_last_node(self, head):
        count = 0
        while head.next is not None:
            count += 1
            head = head.next
        return head, count

    def get_intersection_node(self, head_long, head_short, diff):
        for i in range(diff):
            head_long = head_long.next
        while head_long != head_short:
            head_long, head_short =  head_long.next, head_short.next
        return head_long

    def get_intersection_nodeNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if headA is None or headB is None:
            return None
        end_A, count_A = self.get_last_node(headA)
        end_B, count_B = self.get_last_node(headB)
        if end_A != end_B:
            return None
        if count_A - count_B > 0:
            return get_intersection_node(headA, headB, count_A - count_B)
        else:
            return get_intersection_node(headB, headA, count_B - count_A)
