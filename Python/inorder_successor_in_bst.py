#!/usr/bin/env python
# Given a binary search tree and a node in it, find the in-order successor
# of that node in the BST.

# Note: If the given node has no in-order successor in the tree, return null.

class Solution(object):
    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        if root is None or p is None:
            return None
        node = None
        while root is not None:
            if p.val >= root.val:
                root = root.right
            else:
                node = root
                root = root.left
        return node
