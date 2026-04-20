class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class PathSum {
  /**
   * Recursion - DFS
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool hasPathSum(TreeNode? root, int targetSum) {
    if (root == null) {
      return false;
    }

    if (root.left == null && root.right == null) {
      return (targetSum - root.val) == 0;
    }

    return hasPathSum(root.left, targetSum - root.val) || hasPathSum(root.right, targetSum - root.val);
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursion - DFS
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution1(TreeNode? root, int targetSum) {
    if (root == null) {
      return false;
    }

    if (root.left == null && root.right == null) {
      return targetSum == root.val;
    }

    return solution1(root.left, targetSum - root.val) || solution1(root.right, targetSum - root.val);
  }

  /**
   * Solution 2
   *
   * Iteration - DFS with Stack
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution2(TreeNode? root, int targetSum) {
    if (root == null) {
      return false;
    }

    List<(TreeNode, int)> stack = [(root, targetSum - root.val)];

    while (stack.isNotEmpty) {
      final (node, currentTarget) = stack.removeLast();

      if (node.left == null && node.right == null && currentTarget == 0) {
        return true;
      }

      if (node.right != null) {
        stack.add((node.right!, currentTarget - node.right!.val));
      }

      if (node.left != null) {
        stack.add((node.left!, currentTarget - node.left!.val));
      }
    }

    return false;
  }
}
