#!/usr/bin/env python

# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

# push(x) -- Push element x onto stack.
# pop() -- Removes the element on top of the stack.
# top() -- Get the top element.
# getMin() -- Retrieve the minimum element in the stack.

class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.st = []
        self.mst = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.st.append(x)
        if not self.mst or x <= self.mst[-1]:
            self.mst.append(x)
        

    def pop(self):
        """
        :rtype: nothing
        """
        x = self.st.pop()
        if x == self.mst[-1]:
            self.mst.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.st[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.mst[-1]
