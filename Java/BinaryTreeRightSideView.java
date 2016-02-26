// Given a binary tree, imagine yourself standing on the right side of it, return the values of the 
// nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

public class BinaryTreeRightSideView {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        rightSideView(root, 0, out);
        return out;
    }
    
    void rightSideView(TreeNode root, int level, List<Integer> out) {
        if (root == null) {
            return;
        }
        if (level == out.size()) {
            out.add(root.val);
        }
        rightSideView(root.right, level+1, out);
        rightSideView(root.left, level+1, out);
    }

    public List<Integer> levelOrderRightSideView(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root != null) {
            q.add(root);
        }
        while (!q.isEmpty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode n = q.remove();
                if (i == s-1) {
                    out.add(n.val);
                }
                if (n.left != null) {
                    q.add(n.left);
                }
                if (n.right != null) {
                    q.add(n.right);
                }
            }
        }
        return out;
    }
}
