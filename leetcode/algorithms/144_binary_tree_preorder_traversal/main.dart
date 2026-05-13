class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreePreorderTraversal {
  /**
   * Recursion
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  void addVal(TreeNode? node, List<int> result) {
    if (node != null) {
      result.add(node.val);
      addVal(node.left, result);
      addVal(node.right, result);
    }
  }

  List<int> preorderTraversal(TreeNode? root) {
    List<int> result = List<int>.empty(growable: true);
    addVal(root, result);
    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursion
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  List<int> solution1(TreeNode? root) {
    List<int> result = [];
    _dfs(root, result);
    return result;
  }

  void _dfs(TreeNode? node, List<int> result) {
    if (node == null) {
      return;
    }

    result.add(node.val);

    _dfs(node.left, result);

    _dfs(node.right, result);
  }

  /**
   * Solution 2
   *
   * Iteration
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  List<int> solution2(TreeNode? root) {
    if (root == null) {
      return [];
    }

    List<int> result = [];
    List<TreeNode> stack = [root];

    while (stack.isNotEmpty) {
      TreeNode current = stack.removeLast();

      result.add(current.val);

      if (current.right != null) {
        stack.add(current.right!);
      }
      if (current.left != null) {
        stack.add(current.left!);
      }
    }

    return result;
  }
}
