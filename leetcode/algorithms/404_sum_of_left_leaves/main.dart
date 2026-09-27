class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SumOfLeftLeaves {
  /**
   * Recursion (DFS)
   *
   * Complexities:
   *   N - The Numbder of Nodes in `root`
   *   H - The Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int sumOfLeftLeaves1(TreeNode? root) {
    int sum = 0;

    if (root != null) {
      if (root.left != null) {
        if (root.left!.left == null && root.left!.right == null) {
          sum += root.left!.val;
        }
      }

      sum += sumOfLeftLeaves1(root.left) + sumOfLeftLeaves1(root.right);
    }

    return sum;
  }

  /**
   * Recursion (DFS) with Flag
   *
   * Complexities:
   *   N - The Numbder of Nodes in `root`
   *   H - The Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int addLeftVal(TreeNode? root, bool isLeft) {
    int sum = 0;

    if (root != null) {
      if (isLeft && root.left == null && root.right == null) {
        sum += root.val;
      } else {
        sum += addLeftVal(root.left, true) + addLeftVal(root.right, false);
      }
    }

    return sum;
  }

  int sumOfLeftLeaves2(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    return addLeftVal(root.left, true) + addLeftVal(root.right, false);
  }


  // Solution
  /**
   * Solution 1
   * 
   * Recursion (DFS)
   *
   * Complexities:
   *   N - The Numbder of Nodes in `root`
   *   H - The Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int solution1(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    var sum = 0;
    final left = root.left;

    if (left != null) {
      if (left.left == null && left.right == null) {
        sum += left.val;
      } else {
        sum += solution1(left);
      }
    }

    sum += solution1(root.right);

    return sum;
  }

  /**
   * Solution 2
   * 
   * Recursion (DFS) with Flag
   *
   * Complexities:
   *   N - The Numbder of Nodes in `root`
   *   H - The Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int _dfs(TreeNode? node, bool isLeft) {
    if (node == null) {
      return 0;
    }

    if (node.left == null && node.right == null) {
      return isLeft ? node.val : 0;
    }

    return _dfs(node.left, true) + _dfs(node.right, false);
  }

  int solution2(TreeNode? root) => _dfs(root, false);

  /**
   * Solution 3
   *
   * Iteration (BFS) with Stack
   *
   * Complexities:
   *   N - The Numbder of Nodes in `root`
   *   W - The Width of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(W)
   */
  int solution3(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    var sum = 0;
    final stack = <TreeNode>[root];

    while (stack.isNotEmpty) {
      final node = stack.removeLast();
      final left = node.left;

      if (left != null) {
        if (left.left == null && left.right == null) {
          sum += left.val;
        } else {
          stack.add(left);
        }
      }

      final right = node.right;

      if (right != null) {
        stack.add(right);
      }
    }

    return sum;
  }
}
