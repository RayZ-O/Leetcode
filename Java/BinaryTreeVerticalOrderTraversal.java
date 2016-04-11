// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to 
// bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to right.

// Examples:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its vertical order traversal as:
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
// Given binary tree [3,9,20,4,5,2,7],
//     _3_
//    /   \
//   9    20
//  / \   / \
// 4   5 2   7
// return its vertical order traversal as:
// [
//   [4],
//   [9],
//   [3,5,2],
//   [20],
//   [7]
// ]

public class BinaryTreeVerticalOrderTraversal {
    public List<List<Integer>> verticalOrder(TreeNode root) {
        Map<Integer, List<Integer>> mp = new TreeMap();
        Queue<TreeNode> nodes = new LinkedList<>();
        Queue<Integer> cols = new LinkedList<>();
        if (root != null) {
            nodes.add(root);
            cols.add(0);
        }
        while (!nodes.isEmpty()) {
            TreeNode n = nodes.remove();
            int c = cols.remove();
            mp.putIfAbsent(c, new ArrayList<>());
            mp.get(c).add(n.val);
            if (n.left != null) {
                nodes.add(n.left);
                cols.add(c-1);
            }
            if (n.right != null) {
                nodes.add(n.right);
                cols.add(c + 1);
            }
        }
        return new ArrayList<List<Integer>>(mp.values());
    }
}
