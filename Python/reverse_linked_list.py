#!/usr/bin/env python

# Reverse a singly linked list.

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head;
        n = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return n
