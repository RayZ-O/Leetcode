// Given a binary tree, count the number of uni-value subtrees.

// A Uni-value subtree means all nodes of the subtree have the same value.

// For example:
// Given binary tree,
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// return 4.

public class CountUnivalueSubtrees {
    class SubTreeInfo {
        int count;
        boolean isUnivalue;
        SubTreeInfo(int count, boolean isUnivalue) {
            this.count = count;
            this.isUnivalue = isUnivalue;
        }
    }
    
    SubTreeInfo countUntil(TreeNode root) {
        if (root == null) {
            return new SubTreeInfo(0, true);
        }
        SubTreeInfo l = countUntil(root.left);
        SubTreeInfo r = countUntil(root.right);
        if (l.isUnivalue && r.isUnivalue 
          && (root.left == null || root.left.val == root.val) 
          && (root.right == null || root.right.val == root.val)) {
            return new SubTreeInfo(1 + l.count + r.count, true);
        } else {
            return new SubTreeInfo(l.count + r.count, false);
        }
    }
    
    public int countUnivalSubtrees(TreeNode root) {
        return countUntil(root).count;
    }
}
