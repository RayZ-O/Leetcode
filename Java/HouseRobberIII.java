// The thief has found himself a new place for his thievery again. There is only one entrance to this area,
//  called the "root." Besides the root, each house has one and only one parent house. After a tour, the 
//  smart thief realized that "all houses in this place forms a binary tree". It will automatically contact 
//  the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
// Maximum amount of money the thief can rob = 4 + 5 = 9.

public class HouseRobberIII {
    class MaxMoney {
        int inc; // include root
        int exc; // not include root
        MaxMoney(int inc, int exc) {
            this.inc = inc;
            this.exc = exc;
        }
    }

    public int rob(TreeNode root) {
        MaxMoney max = robTree(root);
        return Math.max(max.inc, max.exc);
    }

    MaxMoney robTree(TreeNode root) {
        if (root == null) {
            return new MaxMoney(0, 0);
        }
        MaxMoney left = robTree(root.left);
        MaxMoney right = robTree(root.right);
        int inc = root.val + left.exc + right.exc;
        int exc = Math.max(left.inc, left.exc) + Math.max(right.inc, right.exc);
        return new MaxMoney(inc, exc);
    }
}
