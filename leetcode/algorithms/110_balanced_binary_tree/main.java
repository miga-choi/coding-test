class BalancedBinaryTree {
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
   *   N - Number of `node`
   *   H - Height of `node`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  private int getMaxDepth(TreeNode node) {
    if (node == null) {
      return 0;
    }

    int leftDepth = getMaxDepth(node.left);
    if (leftDepth < 0) {
      return -1;
    }

    int rightDepth = getMaxDepth(node.right);
    if (rightDepth < 0) {
      return -1;
    }

    if (Math.abs(leftDepth - rightDepth) > 1) {
      return -1;
    }

    return Math.max(leftDepth, rightDepth) + 1;
  }

  public boolean isBalanced(TreeNode root) {
    return getMaxDepth(root) != -1;
  }


  // Solution
  /**
   * DFS
   *
   * Complexities:
   *   N - Number of `node`
   *   H - Height of `node`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  public boolean solution(TreeNode root) {
    return checkHeight(root) != -1;
  }

  private int checkHeight(TreeNode node) {
    if (node == null) {
      return 0;
    }

    int leftHeight = checkHeight(node.left);
    if (leftHeight == -1) {
      return -1;
    }

    int rightHeight = checkHeight(node.right);
    if (rightHeight == -1) {
      return -1;
    }

    if (Math.abs(leftHeight - rightHeight) > 1) {
      return -1;
    }

    return Math.max(leftHeight, rightHeight) + 1;
  }
}
