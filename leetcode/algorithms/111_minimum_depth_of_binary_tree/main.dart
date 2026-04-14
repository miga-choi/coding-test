import 'dart:collection';
import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class MinimumDepthOfBinaryTree {
  /**
   * Recursion: DFS
   * 
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int minDepth(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = minDepth(root.left);
    int rightDepth = minDepth(root.right);

    if (leftDepth == 0 || rightDepth == 0) {
      return max(leftDepth, rightDepth) + 1;
    }

    return min(leftDepth, rightDepth) + 1;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Iteration: BFS (Queue)
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   W - Width of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(W)
   */
  int solution1(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    Queue<TreeNode> queue = Queue();
    queue.add(root);
    int depth = 1;

    while (queue.isNotEmpty) {
      int levelSize = queue.length;

      for (int i = 0; i < levelSize; i++) {
        TreeNode current = queue.removeFirst();

        if (current.left == null && current.right == null) {
          return depth;
        }

        if (current.left != null) {
          queue.add(current.left!);
        }
        if (current.right != null) {
          queue.add(current.right!);
        }
      }

      depth++;
    }

    return depth;
  }

  /**
   * Solution 2
   * 
   * Recursion: DFS
   * 
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  int solution2(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    if (root.left == null) {
      return solution2(root.right) + 1;
    }
    if (root.right == null) {
      return solution2(root.left) + 1;
    }

    return min(solution2(root.left), solution2(root.right)) + 1;
  }
}
