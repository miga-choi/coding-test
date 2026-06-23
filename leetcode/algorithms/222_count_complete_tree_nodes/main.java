class CountCompleteTreeNodes {
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
     * DFS
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(logᴺ)
     */
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }

        return countNodes(root.left) + countNodes(root.right) + 1;
    }


    // Solution
    /**
     * Perfect Binary Tree
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   - Time Complexity: O(log₂ᴺ)
     *   - Space Complexity: O(logᴺ)
     */
    public int solution(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + solution(root.left) + solution(root.right);
    }

    private int getLeftHeight(TreeNode node) {
        int height = 0;

        while (node != null) {
            height++;
            node = node.left;
        }

        return height;
    }

    private int getRightHeight(TreeNode node) {
        int height = 0;

        while (node != null) {
            height++;
            node = node.right;
        }

        return height;
    }
}
