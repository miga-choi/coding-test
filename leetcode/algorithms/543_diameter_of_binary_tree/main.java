class DiameterOfBinaryTree {
    class TreeNode {
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
     * - Space Complexity: O(H)
     */
    private int diameter = 0;

    private int getMaxDiameter(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int leftDiameter = getMaxDiameter(node.left);
        int rightDiameter = getMaxDiameter(node.right);

        if (leftDiameter + rightDiameter > diameter) {
            diameter = leftDiameter + rightDiameter;
        }

        return Math.max(leftDiameter, rightDiameter) + 1;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        getMaxDiameter(root);

        return diameter;
    }


    // Solution
    /**
     * Recursion: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    private int maxDiameter = 0;

    public int Solution(TreeNode root) {
        calculateDepth(root);
        return maxDiameter;
    }

    private int calculateDepth(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int leftDepth = calculateDepth(node.left);
        int rightDepth = calculateDepth(node.right);

        maxDiameter = Math.max(maxDiameter, leftDepth + rightDepth);

        return Math.max(leftDepth, rightDepth) + 1;
    }
}
