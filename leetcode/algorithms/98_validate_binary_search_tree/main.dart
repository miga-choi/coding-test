class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class ValidateBinarySearchTree {
  /**
   * Recursion: DFS
   * 
   * Complexities:
   *   N - Size of `node`
   *   H - Height of `node`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
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
   * Recursive with Range
   *
   * Complexities:
   *   N - Size of `node`
   *   H - Height of `node`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  bool _validate(TreeNode? node, int? min, int? max) {
    if (node == null) {
      return true;
    }

    if (min != null && node.val <= min) {
      return false;
    }

    if (max != null && node.val >= max) {
      return false;
    }

    return _validate(node.left, min, node.val) &&
        _validate(node.right, node.val, max);
  }

  bool solution1(TreeNode? root) {
    return _validate(root, null, null);
  }

  /**
   * Solution 2
   * 
   * Inorder Traversal
   * 
   * Complexities:
   *   N - Size of `node`
   *   H - Height of `node`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int? prev;

  bool _inorder(TreeNode? node) {
    if (node == null) {
      return true;
    }

    if (!_inorder(node.left)) {
      return false;
    }

    if (prev != null && node.val <= prev!) {
      return false;
    }
    prev = node.val;

    return _inorder(node.right);
  }

  bool solution2(TreeNode? root) {
    prev = null;
    return _inorder(root);
  }
}
