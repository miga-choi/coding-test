import 'dart:collection';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreeLevelOrderTraversal {
  /**
   * BFS
   * 
   * Complexities:
   *   N - Size of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<List<int>> levelOrder(TreeNode? root) {
    if (root == null) {
      return [];
    }

    final List<List<int>> result = [];

    final Queue<TreeNode?> q = Queue();
    q.add(root);

    while (q.isNotEmpty) {
      final Queue<TreeNode?> tempQ = Queue.from(q);
      q.clear();

      final List<int> array = [];

      while (tempQ.isNotEmpty) {
        final TreeNode? node = tempQ.removeFirst();

        if (node == null) {
          break;
        }

        array.add(node.val);

        if (node.left != null) {
          q.add(node.left);
        }
        if (node.right != null) {
          q.add(node.right);
        }
      }

      result.add(array);
    }

    return result;
  }


  // Solution
  /**
   * BFS
   * 
   * Complexities:
   *   N - Size of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<List<int>> solution(TreeNode? root) {
    if (root == null) {
      return [];
    }

    List<List<int>> result = [];

    Queue<TreeNode> queue = Queue();
    queue.add(root);

    while (queue.isNotEmpty) {
      int levelSize = queue.length;
      List<int> currentLevel = [];

      for (int i = 0; i < levelSize; i++) {
        TreeNode node = queue.removeFirst();
        currentLevel.add(node.val);

        if (node.left != null) {
          queue.add(node.left!);
        }
        if (node.right != null) {
          queue.add(node.right!);
        }
      }

      result.add(currentLevel);
    }

    return result;
  }
}
