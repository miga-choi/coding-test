/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


class MaximumDepthOfBinaryTree {

  public class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
      this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }

  public int maxDepth(TreeNode root) {
    if (root == null) {
      return 0;
    }
    return returnDepth(0, root);
  }

  public int returnDepth(int depth_, TreeNode node_) {
    int depth = depth_ + 1;
    if (node_.left != null) {
      int leftDepth = returnDepth(depth_ + 1, node_.left);
      if (leftDepth > depth) {
        depth = leftDepth;
      }
    }
    if (node_.right != null) {
      int rightDepth = returnDepth(depth_ + 1, node_.right);
      if (rightDepth > depth) {
        depth = rightDepth;
      }
    }
    return depth;
  }

  // Best Solution
  public int bestSolution(TreeNode root) {
    // Base Condition
    if (root == null) return 0;
    // Hypothesis
    int left = bestSolution(root.left);
    int right = bestSolution(root.right);
    // Induction
    return Math.max(left, right) + 1;
  }
}
