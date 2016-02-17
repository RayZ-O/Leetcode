// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3

public class SymmetricTree {
    boolean isSymmetric(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null || p.val != q.val) {
            return false;
        }
        return isSymmetric(p.left, q.right) && isSymmetric(q.left, p.right);
    }

    public boolean isSymmetric(TreeNode root) {
        return root == null ? true : isSymmetric(root.left, root.right);
    }

    public boolean isSymmetricIter(TreeNode root) {
        if (root == null) {
            return true;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root.left);
        q.add(root.right);
        while (!q.isEmpty()) {
            TreeNode m = q.remove();
            TreeNode n = q.remove();
            if (m == null && n == null) {
                continue;
            }
            if (m == null || n == null || m.val != n.val) {
                return false;
            }
            q.add(m.left);
            q.add(n.right);
            q.add(n.left);
            q.add(m.right);
        }
        return true;
    }
}
