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

class Solution {

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

  public boolean isBalanced(TreeNode root) {
    return checkDepth(root) > -1;
  }

  public int checkDepth(TreeNode node_) {
    if (node_ == null) {
      return 0;
    }

    int leftDepth = checkDepth(node_.left);
    int rightDepth = checkDepth(node_.right);

    if (
      leftDepth == -1 ||
      rightDepth == -1 ||
      Math.abs(leftDepth - rightDepth) > 1
    ) {
      return -1;
    }

    return Math.max(leftDepth, rightDepth) + 1;
  }
}
