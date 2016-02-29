// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

public class ConvertSortedArrayToBinarySearchTree {
    TreeNode sortedArrayToBST(int[] nums, int l, int r) {
        if (l > r) {
            return null;
        }
        int mid = l + (r - l)/2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = sortedArrayToBST(nums, l, mid - 1);
        root.right = sortedArrayToBST(nums, mid + 1, r);
        return root;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBST(nums, 0, nums.length - 1);
    }
}
