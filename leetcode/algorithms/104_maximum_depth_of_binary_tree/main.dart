import 'dart:collection';
import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class MaximumDepthOfBinaryTree {
  /**
   * Recursion - DFS
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int maxDepth(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    final int left = maxDepth(root.left);
    final int right = maxDepth(root.right);

    return max(left, right) + 1;
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursion - DFS
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int solution1(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = solution1(root.left);
    int rightDepth = solution1(root.right);

    return max(leftDepth, rightDepth) + 1;
  }

  /**
   * Solution 2
   *
   * Iteration - BFS
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int solution2(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    Queue<TreeNode> queue = Queue();
    queue.add(root);
    int depth = 0;

    while (queue.isNotEmpty) {
      int levelSize = queue.length;

      for (int i = 0; i < levelSize; i++) {
        TreeNode node = queue.removeFirst();

        if (node.left != null) {
          queue.add(node.left!);
        }

        if (node.right != null) {
          queue.add(node.right!);
        }
      }

      depth++;
    }

    return depth;
  }
}
