import java.util.LinkedList;
import java.util.Queue;

class MaximumDepthOfBinaryTree {
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
   * Recursion - DFS
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  public int maxDepth(TreeNode root) {
    if (root == null) {
      return 0;
    }

    int left = maxDepth(root.left);
    int right = maxDepth(root.right);

    return Math.max(left, right) + 1;
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursion - DFS
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  public int solution1(TreeNode root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = solution1(root.left);
    int rightDepth = solution1(root.right);

    return Math.max(leftDepth, rightDepth) + 1;
  }

  /**
   * Solution 2
   *
   * Iteration - BFS
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  public int solution2(TreeNode root) {
    if (root == null) {
      return 0;
    }

    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    int depth = 0;

    while (!queue.isEmpty()) {
      int levelSize = queue.size();

      for (int i = 0; i < levelSize; i++) {
        TreeNode node = queue.poll();

        if (node.left != null) {
          queue.offer(node.left);
        }

        if (node.right != null) {
          queue.offer(node.right);
        }
      }

      depth++;
    }

    return depth;
  }
}
