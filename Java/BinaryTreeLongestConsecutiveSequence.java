// Given a binary tree, find the length of the longest consecutive sequence path.

// The path refers to any sequence of nodes from some starting node to any node in the tree along
// the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

// For example,
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
// Longest consecutive sequence path is 3-4-5, so return 3.
//    2
//     \
//      3
//     /
//    2
//   /
//  1
// Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

public class BinaryTreeLongestConsecutiveSequence {
    int max = 0;

    void longestConsecutive(TreeNode root, int count) {
        if (root == null) {
            max = Math.max(max, count);
            return;
        }
        if (root.left == null || root.left.val == root.val + 1)
            longestConsecutive(root.left, count + 1);
        else {
            max = Math.max(max, count + 1);
            longestConsecutive(root.left, 0);
        }

        if (root.right == null || root.right.val == root.val + 1)
            longestConsecutive(root.right, count + 1);
        else {
            max = Math.max(max, count + 1);
            longestConsecutive(root.right, 0);
        }
    }

    public int longestConsecutive(TreeNode root) {
        longestConsecutive(root, 0);
        return max;
    }
}
