class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreeInorderTraversal {
  /**
   * Recursion
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
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
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  void _inorderHelper(TreeNode? node, List<int> result) {
    if (node == null) {
      return;
    }

    _inorderHelper(node.left, result);
    result.add(node.val);
    _inorderHelper(node.right, result);
  }

  List<int> solution1(TreeNode? root) {
    List<int> result = [];
    _inorderHelper(root, result);
    return result;
  }

  /**
   * Solution 2
   * 
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  List<int> solution2(TreeNode? root) {
    List<int> result = [];
    List<TreeNode> stack = [];
    TreeNode? current = root;

    while (current != null || stack.isNotEmpty) {
      while (current != null) {
        stack.add(current);
        current = current.left;
      }

      current = stack.removeLast();
      result.add(current.val);

      current = current.right;
    }

    return result;
  }

  /**
   * Solution 3
   * 
   * Morris Traversal
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  List<int> solution3(TreeNode? root) {
    List<int> result = [];
    TreeNode? current = root;

    while (current != null) {
      if (current.left == null) {
        result.add(current.val);
        current = current.right;
      } else {
        TreeNode predecessor = current.left!;

        while (predecessor.right != null && predecessor.right != current) {
          predecessor = predecessor.right!;
        }

        if (predecessor.right == null) {
          predecessor.right = current;
          current = current.left;
        } else {
          predecessor.right = null;
          result.add(current.val);
          current = current.right;
        }
      }
    }

    return result;
  }
}
