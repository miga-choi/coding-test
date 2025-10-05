import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BalancedBinaryTree {
  /**
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  int _getMaxDepth(TreeNode? node) {
    if (node == null) {
      return 0;
    }

    int leftDepth = _getMaxDepth(node.left);
    if (leftDepth < 0) {
      return -1;
    }

    int rightDepth = _getMaxDepth(node.right);
    if (rightDepth < 0) {
      return -1;
    }

    if ((leftDepth - rightDepth).abs() > 1) {
      return -1;
    }

    return max(leftDepth, rightDepth) + 1;
  }

  bool isBalanced(TreeNode? root) {
    return _getMaxDepth(root) != -1;
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursion: DFS (Top-down)
   * - Time Complexity: O(N * Logᴺ)
   * - Space Complexity: O(H)
   */
  int _getHeight(TreeNode? node) {
    if (node == null) {
      return 0;
    }

    return 1 + max(_getHeight(node.left), _getHeight(node.right));
  }

  bool solution1(TreeNode? root) {
    if (root == null) {
      return true;
    }

    int leftHeight = _getHeight(root.left);
    int rightHeight = _getHeight(root.right);
    if ((leftHeight - rightHeight).abs() > 1) {
      return false;
    }

    return isBalanced(root.left) && isBalanced(root.right);
  }

  /**
   * Solution 2
   *
   * Recursion: DFS (Bottom-up)
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  int _checkHeight(TreeNode? node) {
    if (node == null) {
      return 0;
    }

    int leftHeight = _checkHeight(node.left);
    if (leftHeight == -1) {
      return -1;
    }

    int rightHeight = _checkHeight(node.right);
    if (rightHeight == -1) {
      return -1;
    }

    if ((leftHeight - rightHeight).abs() > 1) {
      return -1;
    }

    return 1 + max(leftHeight, rightHeight);
  }

  bool solution2(TreeNode? root) {
    return _checkHeight(root) != -1;
  }
}
