// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]

public class BinaryTreePaths {
    void binaryTreePaths(TreeNode root, StringBuilder sb, List<String> out) {
        if (root == null) {
            return;
        }
        int len = sb.length();
        if (len != 0) {
            sb.append("->");
        }
        sb.append(root.val);
        if (root.left == null && root.right == null) {
            out.add(sb.toString());
        }
        binaryTreePaths(root.left, sb, out);
        binaryTreePaths(root.right, sb, out);
        sb.setLength(len);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> out = new ArrayList<>();
        binaryTreePaths(root, new StringBuilder(), out);
        return out;
    }
}
