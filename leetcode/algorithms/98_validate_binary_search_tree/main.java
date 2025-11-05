import java.util.Stack;

class ValidateBinarySearchTree {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    /**
     * Recursion: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    private boolean helper(TreeNode node, long minVal, long maxVal) {
        if (node == null) {
            return true;
        }

        if ((long) node.val <= minVal || (long) node.val >= maxVal) {
            return false;
        }

        return helper(node.left, minVal, node.val) && helper(node.right, node.val, maxVal);
    }

    public boolean isValidBST(TreeNode root) {
        return helper(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }


    // Solution
    /**
     * Solution 1
     * 
     * Recursion: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    private boolean isValid(TreeNode node, Integer min, Integer max) {
        if (node == null) {
            return true;
        }

        if (min != null && node.val <= min) {
            return false;
        }

        if (max != null && node.val >= max) {
            return false;
        }

        return isValid(node.left, min, node.val) && isValid(node.right, node.val, max);
    }

    public boolean solution1(TreeNode root) {
        return isValid(root, null, null);
    }

    /**
     * Solution 2
     * 
     * Iteration: Inorder Traversal
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    public boolean solution2(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        Integer prev = null;

        TreeNode current = root;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            current = stack.pop();

            if (prev != null && current.val <= prev) {
                return false;
            }

            prev = current.val;

            current = current.right;
        }

        return true;
    }
}
