import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BalancedBinaryTree {
  /**
   * DFS
   *
   * Complexities:
   *   N - Number of `node`
   *   H - Height of `node`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
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
   * DFS
   *
   * Complexities:
   *   N - Number of `node`
   *   H - Height of `node`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  bool solution(TreeNode? root) {
    return _checkHeightAndBalance(root) != -1;
  }

  int _checkHeightAndBalance(TreeNode? node) {
    if (node == null) {
      return 0;
    }

    int leftHeight = _checkHeightAndBalance(node.left);
    if (leftHeight == -1) {
      return -1;
    }

    int rightHeight = _checkHeightAndBalance(node.right);
    if (rightHeight == -1) {
      return -1;
    }

    if ((leftHeight - rightHeight).abs() > 1) {
      return -1;
    }

    return 1 + max(leftHeight, rightHeight);
  }
}
