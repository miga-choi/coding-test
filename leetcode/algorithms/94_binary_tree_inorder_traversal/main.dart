class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreeInorderTraversal {
  /**
   * Recursion
   *
   * Complexities:
   *   N - Size of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> inorderTraversal(TreeNode? root) {
    if (root == null) {
      return List<int>.empty();
    }

    List<int> result = List<int>.empty(growable: true);

    int addVal(TreeNode node) {
      if (node.left != null) {
        addVal(node.left!);
      }

      result.add(node.val);

      if (node.right != null) {
        addVal(node.right!);
      }

      return node.val;
    }

    addVal(root);

    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursion
   *
   * Complexities:
   *   N - Size of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  void _inorder(TreeNode? node, List<int> result) {
    if (node == null) {
      return;
    }

    _inorder(node.left, result);

    result.add(node.val);

    _inorder(node.right, result);
  }

  List<int> solution1(TreeNode? root) {
    List<int> result = [];

    _inorder(root, result);

    return result;
  }

  /**
   * Solution 2
   *
   * Iteration
   *
   * Complexities:
   *   N - Size of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> solution2(TreeNode? root) {
    List<int> result = [];
    List<TreeNode> stack = [];
    TreeNode? curr = root;

    while (curr != null || stack.isNotEmpty) {
      while (curr != null) {
        stack.add(curr);
        curr = curr.left;
      }

      curr = stack.removeLast();

      result.add(curr.val);

      curr = curr.right;
    }

    return result;
  }
}
