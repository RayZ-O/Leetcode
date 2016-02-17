// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left
// to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

public class BinaryTreeZigzagLevelOrderTraversal {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<>();
        if (root == null) {
            return out;
        }
        LinkedList<TreeNode> nodes = new LinkedList<>();
        nodes.add(root);
        boolean d = false;
        while (!nodes.isEmpty()) {
            int i = nodes.size();
            List<Integer> cur = new ArrayList<>();
            while (i-- > 0) {
                TreeNode n = nodes.remove();
                cur.add(n.val);
                if (n.left != null) {
                    nodes.add(n.left);
                }
                if (n.right != null) {
                    nodes.add(n.right);
                }
            }
            if (d) {
                Collections.reverse(cur);
            }
            out.add(cur);
            d = !d;
        }
        return out;
    }
}
