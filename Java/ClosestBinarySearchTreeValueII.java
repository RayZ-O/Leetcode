// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to 
// the target.

// Note:
// Given target value is a floating point.
// You may assume k is always valid, that is: k ≤ total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
// Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

public class ClosestBinarySearchTreeValueII {
    private Stack<TreeNode> pred = new Stack<>();
    private Stack<TreeNode> succ = new Stack<>();

    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> out = new ArrayList<>();

        while (root != null) {
            if (target < root.val) {
                succ.push(root);
                root = root.left;
            } else {
                pred.push(root);
                root = root.right;
            }
        }

        while (k > 0) {
            if (succ.isEmpty() && pred.isEmpty()) {
                break;
            } else if (pred.isEmpty()) {
                out.add(getSuccessor());
            } else if (succ.isEmpty()) {
                out.add(getPredecessor());
            } else if (Math.abs(pred.peek().val - target) < Math.abs(succ.peek().val - target)) {
                out.add(getPredecessor());
            } else {
                out.add(getSuccessor());
            }
            k--;
        }
        return out;
    }

    int getPredecessor() {
        TreeNode p = pred.pop();
        TreeNode n = p.left;
        while (n != null) {
            pred.push(n);
            n = n.right;            
        }
        return p.val;
    }

    int getSuccessor() {
        TreeNode s = succ.pop();
        TreeNode n = s.right;
        while (n != null) {            
            succ.push(n);
            n = n.left;
        }
        return s.val;
    }
}
