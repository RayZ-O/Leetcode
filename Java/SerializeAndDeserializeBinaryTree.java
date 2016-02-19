// Serialization is the process of converting a data structure or object into a sequence of bits so that
// it can be stored in a file or memory buffer, or transmitted across a network connection link to be
// reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
// serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be
// serialized to a string and this string can be deserialized to the original tree structure.

// For example, you may serialize the following tree

//     1
//    / \
//   2   3
//      / \
//     4   5

public class SerializeAndDeserializeBinaryTree {
    void collect(TreeNode root, StringBuilder sb) {
        if (sb.length() != 0) sb.append(",");
        if (root == null) {
            sb.append("null");
            return;
        }
        sb.append(root.val);
        collect(root.left, sb);
        collect(root.right, sb);
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        collect(root, sb);
        return sb.toString();
    }

    TreeNode build(LinkedList<String> preorder) {
        String s = preorder.remove();
        if (s.equals("null")) {
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(s));
        node.left = build(preorder);
        node.right = build(preorder);
        return node;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        LinkedList<String> preorder = new LinkedList(Arrays.asList(data.split(",")));
        return build(preorder);
    }
}
