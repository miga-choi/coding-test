import java.util.LinkedList;
import java.util.Queue;

class InvertBinaryTree {
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
     * Recursiont: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }

        TreeNode temp = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(temp);

        return root;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Recursiont: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    public TreeNode solution1(TreeNode root) {
        if (root == null) {
            return null;
        }

        TreeNode leftSubtree = invertTree(root.left);
        TreeNode rightSubtree = invertTree(root.right);

        root.left = rightSubtree;
        root.right = leftSubtree;

        return root;
    }

    /**
     * Solution 2
     * 
     * Iteration: BFS (Queue)
     * - Time Complexity: O(N)
     * - Space Complexity: O(W)
     */
    public TreeNode solution2(TreeNode root) {
        if (root == null) {
            return null;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();

            TreeNode temp = currentNode.left;
            currentNode.left = currentNode.right;
            currentNode.right = temp;

            if (currentNode.left != null) {
                queue.offer(currentNode.left);
            }
            if (currentNode.right != null) {
                queue.offer(currentNode.right);
            }
        }

        return root;
    }
}
