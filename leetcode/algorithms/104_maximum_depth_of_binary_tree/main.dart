import 'dart:collection';
import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

typedef _NodeDepthRecord = (TreeNode node, int depth);

class MaximumDepthOfBinaryTree {
  /**
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
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
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  int solution1(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = maxDepth(root.left);
    int rightDepth = maxDepth(root.right);

    return max(leftDepth, rightDepth) + 1;
  }

  /**
   * Solution 2
   * 
   * Iteration: BFS (Queue)
   * - Time Complexity: O(N)
   * - Space Complexity: O(W)
   */
  int solution2(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    Queue<TreeNode> queue = Queue();
    queue.add(root);
    int depth = 0;

    while (queue.isNotEmpty) {
      depth++;
      int levelSize = queue.length;

      for (int i = 0; i < levelSize; i++) {
        TreeNode currentNode = queue.removeFirst();

        if (currentNode.left != null) {
          queue.add(currentNode.left!);
        }
        if (currentNode.right != null) {
          queue.add(currentNode.right!);
        }
      }
    }

    return depth;
  }

  /**
   * Solution 3
   * 
   * Iteration: DFS (Stack)
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  int solution3(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    List<_NodeDepthRecord> stack = [];
    stack.add((root, 1));
    int maxD = 0;

    while (stack.isNotEmpty) {
      _NodeDepthRecord current = stack.removeLast();
      TreeNode node = current.$1;
      int depth = current.$2;

      maxD = max(maxD, depth);

      if (node.right != null) {
        stack.add((node.right!, depth + 1));
      }
      if (node.left != null) {
        stack.add((node.left!, depth + 1));
      }
    }

    return maxD;
  }
}
