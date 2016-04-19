// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// The update(i, val) function modifies nums by updating the element at index i to val.
// Example:
// Given nums = [1, 3, 5]

// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
// Note:
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.

public class NumArray {
    class SegmentTreeNode {
        int start;
        int end;
        int sum;
        SegmentTreeNode left;
        SegmentTreeNode right;
        SegmentTreeNode(int s, int e) {
            start = s;
            end = e;
        }
    }

    private SegmentTreeNode buildSegmentTree(int[] nums, int start, int end) {
        if (start > end) {
            return null;
        }
        SegmentTreeNode root = new SegmentTreeNode(start, end);
        if (start == end) {
            root.sum = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            root.left = buildSegmentTree(nums, start, mid);
            root.right = buildSegmentTree(nums, mid + 1, end);
            root.sum = root.left.sum + root.right.sum;
        }
        return root;
    }

    private void update(SegmentTreeNode node, int i, int val) {
        if (node.start == node.end) {
            node.sum = val;
        } else {
            int mid = node.start + (node.end - node.start) / 2;
            if (i <= mid) {
                update(node.left, i, val);
            } else {
                update(node.right, i, val);
            }
            node.sum = node.left.sum + node.right.sum;
        }
    }

    private int query(SegmentTreeNode node, int start, int end) {
        if (node.start == start && node.end == end) {
            return node.sum;
        }
        int mid = node.start + (node.end - node.start) / 2;
        if (end <= mid) {
            return query(node.left, start, end);
        } else if (start > mid) {
            return query(node.right, start, end);
        } else {
            return query(node.left, start, mid) + query(node.right, mid + 1, end);
        }
    }

    private SegmentTreeNode root = null;

    public NumArray(int[] nums) {
        root = buildSegmentTree(nums, 0, nums.length-1);
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    public int sumRange(int i, int j) {
        return query(root, i, j);
    }
}
