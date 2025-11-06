class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class ValidateBinarySearchTree {
  /**
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  bool _helper(TreeNode? node, int? minVal, int? maxVal) {
    if (node == null) {
      return true;
    }

    if (minVal != null && node.val <= minVal) {
      return false;
    }

    if (maxVal != null && node.val >= maxVal) {
      return false;
    }

    return _helper(node.left, minVal, node.val) &&
        _helper(node.right, node.val, maxVal);
  }

  bool isValidBST(TreeNode? root) {
    return _helper(root, null, null);
  }


  // Solution
  /**
   * Solution 1
   * 
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  bool _isValid(TreeNode? node, int? min, int? max) {
    if (node == null) {
      return true;
    }

    if (min != null && node.val <= min) {
      return false;
    }

    if (max != null && node.val >= max) {
      return false;
    }

    return _isValid(node.left, min, node.val) &&
        _isValid(node.right, node.val, max);
  }

  bool solution1(TreeNode? root) {
    return _isValid(root, null, null);
  }

  /**
   * Solution 2
   * 
   * Recursion: Inorder Traversal
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  int? prevVal;

  bool solution2(TreeNode? root) {
    if (root == null) {
      return true;
    }

    if (!solution2(root.left)) {
      return false;
    }

    if (prevVal != null && root.val <= prevVal!) {
      return false;
    }

    prevVal = root.val;

    return isValidBST(root.right);
  }
}
