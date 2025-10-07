import java.util.LinkedList;
import java.util.Queue;

class MinimumDepthOfBinaryTree {
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
   * - Space Complexity: O(H)
   */
  public int minDepth(TreeNode root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = minDepth(root.left);
    int rightDepth = minDepth(root.right);

    if (leftDepth == 0 || rightDepth == 0) {
      return Math.max(leftDepth, rightDepth) + 1;
    }

    return Math.min(leftDepth, rightDepth) + 1;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Iteration: BFS (Queue)
   * - Time Complexity: O(N)
   * - Space Complexity: O(W)
   */
  public int solution1(TreeNode root) {
    if (root == null) {
      return 0;
    }

    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    int depth = 1;

    while (!queue.isEmpty()) {
      int levelSize = queue.size();

      for (int i = 0; i < levelSize; i++) {
        TreeNode currentNode = queue.poll();

        if (currentNode.left == null && currentNode.right == null) {
          return depth;
        }

        if (currentNode.left != null) {
          queue.offer(currentNode.left);
        }
        if (currentNode.right != null) {
          queue.offer(currentNode.right);
        }
      }

      depth++;
    }

    return depth;
  }

  /**
   * Solution 2
   * 
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  public int solution2(TreeNode root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = solution2(root.left);
    int rightDepth = solution2(root.right);

    if (leftDepth == 0 || rightDepth == 0) {
      return leftDepth + rightDepth + 1;
    } else {
      return Math.min(leftDepth, rightDepth) + 1;
    }
  }
}
