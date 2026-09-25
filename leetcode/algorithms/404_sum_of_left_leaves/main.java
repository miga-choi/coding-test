import java.util.ArrayDeque;
import java.util.Deque;

class SumOfLeftLeaves {
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
     * Recursion (DFS)
     *
     * Complexities:
     *   N - The Numbder of Nodes in `root`
     *   H - The Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int result = 0;

        if (root.left != null) {
            if (root.left.left == null && root.left.right == null) {
                result += root.left.val;
            } else {
                result += sumOfLeftLeaves(root.left);
            }
        }

        result += sumOfLeftLeaves(root.right);

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Recursion (DFS)
     *
     * Complexities:
     *   N - The Numbder of Nodes in `root`
     *   H - The Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    public int solution1(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int sum = 0;
        TreeNode left = root.left;

        if (left != null && left.left == null && left.right == null) {
            sum += left.val;
        } else {
            sum += sumOfLeftLeaves(left);
        }

        sum += sumOfLeftLeaves(root.right);

        return sum;
    }

    /**
     * Solution 2
     *
     * Iteration (BFS) with Deque
     *
     * Complexities:
     *   N - The Numbder of Nodes in `root`
     *   W - The Width of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(W)
     */
    public int solution2(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int sum = 0;
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            if (node.left != null) {
                if (node.left.left == null && node.left.right == null) {
                    sum += node.left.val;
                } else {
                    queue.offer(node.left);
                }
            }

            if (node.right != null) {
                queue.offer(node.right);
            }
        }

        return sum;
    }
}
