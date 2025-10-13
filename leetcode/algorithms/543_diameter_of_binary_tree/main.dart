import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class DiameterOfBinaryTree {
  /**
   * Recursion: DFS (Bottom-up)
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  int diameterOfBinaryTree(TreeNode? root) {
    int maxDiameter = 0;

    int getMaxDiameter(TreeNode? node) {
      if (node == null) {
        return 0;
      }

      final int leftDiameter = getMaxDiameter(node.left);
      final int rightDiameter = getMaxDiameter(node.right);

      if (leftDiameter + rightDiameter > maxDiameter) {
        maxDiameter = leftDiameter + rightDiameter;
      }

      return max(leftDiameter, rightDiameter) + 1;
    }

    getMaxDiameter(root);

    return maxDiameter;
  }


  // Solution
  /**
   * Recursion: DFS (Bottom-up)
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  int _maxDiameter = 0;

  int _depth(TreeNode? node) {
    if (node == null) {
      return 0;
    }

    int leftDepth = _depth(node.left);
    int rightDepth = _depth(node.right);

    _maxDiameter = max(_maxDiameter, leftDepth + rightDepth);

    return 1 + max(leftDepth, rightDepth);
  }

  int solution(TreeNode? root) {
    _depth(root);
    return _maxDiameter;
  }
}
