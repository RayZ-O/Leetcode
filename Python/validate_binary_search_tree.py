#!/usr/bin/env python
# Given a binary tree, determine if it is a valid binary search tree (BST).

# Assume a BST is defined as follows:

# The left subtree of a node contains only nodes with keys less than the node's key.
# The right subtree of a node contains only nodes with keys greater than the node's key.
# Both the left and right subtrees must also be binary search trees.

class Solution(object):
    def __init__(self):
        self.prev = None

    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        if not self.isValidBST(root.left):
            return False
        if self.prev is not None and self.prev.val >= root.val:
            return False
        self.prev = root
        return self.isValidBST(root.right)
