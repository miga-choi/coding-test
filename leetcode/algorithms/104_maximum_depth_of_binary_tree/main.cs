using System;
using System.Collections.Generic;

public class MaximumDepthOfBinaryTree {
    public class TreeNode {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public int MaxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = MaxDepth(root.left);
        int right = MaxDepth(root.right);

        return Math.Max(left, right) + 1;
    }


    // Solution
    // Solution 1: Depth-First Search
    public int solution1(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftMaxDepth = solution1(root.left);
        int rightMaxDepth = solution1(root.right);

        return Math.Max(leftMaxDepth, rightMaxDepth) + 1;
    }

    // Solution 2: Breadth-First Search
    public int solution2(TreeNode root) {
        if (root == null) {
            return 0;
        }

        var queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        var depth = 0;

        while (queue.Count != 0) {
            var size = queue.Count;

            for (var i = 0; i < size; i++) {
                var current = queue.Dequeue();
                if (current.left != null) {
                    queue.Enqueue(current.left);
                }
                if (current.right != null) {
                    queue.Enqueue(current.right);
                }
            }

            depth++;
        }

        return depth;
    }
}
