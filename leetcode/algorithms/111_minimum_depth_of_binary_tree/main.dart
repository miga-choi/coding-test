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
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
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
   * - Time Complexity: O(N)
   * - Space Complexity: O(W)
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
        TreeNode currentNode = queue.removeFirst();

        if (currentNode.left == null && currentNode.right == null) {
          return depth;
        }

        if (currentNode.left != null) {
          queue.add(currentNode.left!);
        }
        if (currentNode.right != null) {
          queue.add(currentNode.right!);
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
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  int solution2(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = solution2(root.left);
    int rightDepth = solution2(root.right);

    if (leftDepth == 0 || rightDepth == 0) {
      return leftDepth + rightDepth + 1;
    } else {
      return min(leftDepth, rightDepth) + 1;
    }
  }
}
