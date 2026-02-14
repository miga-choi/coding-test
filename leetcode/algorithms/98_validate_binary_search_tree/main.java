
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
     * 
     * Complexities:
     *   N - Size of `node`
     *   H - Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
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
     * Recursion: DFS
     * 
     * Complexities:
     *   N - Size of `node`
     *   H - Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    private boolean validate(TreeNode node, Integer min, Integer max) {
        if (node == null) {
            return true;
        }

        if (min != null && node.val <= min) {
            return false;
        }
        if (max != null && node.val >= max) {
            return false;
        }

        return validate(node.left, min, node.val) && validate(node.right, node.val, max);
    }

    public boolean solution1(TreeNode root) {
        return validate(root, null, null);
    }
}
