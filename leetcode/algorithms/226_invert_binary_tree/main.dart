import 'dart:collection';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class InvertBinaryTree {
  /**
   * Recursiont: DFS
   *
   * Complexities:
   *   N - The Number of nodes in `root`
   *   H - THe Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  TreeNode? invertTree(TreeNode? root) {
    if (root == null) {
      return null;
    }

    TreeNode? temp = root.left;
    root.left = invertTree(root.right);
    root.right = invertTree(temp);

    return root;
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursiont: DFS
   *
   * Complexities:
   *   N - The Number of nodes in `root`
   *   H - THe Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  TreeNode? solution1(TreeNode? root) {
    if (root == null) {
      return null;
    }

    TreeNode? temp = root.left;
    root.left = root.right;
    root.right = temp;

    solution1(root.left);
    solution1(root.right);

    return root;
  }

  /**
   * Solution 2
   *
   * Iteration: BFS (Queue)
   *
   * Complexities:
   *   N - The Number of nodes in `root`
   *   W - THe Width of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(W)
   */
  TreeNode? solution2(TreeNode? root) {
    if (root == null) {
      return null;
    }

    Queue<TreeNode> queue = Queue();
    queue.add(root);

    while (queue.isNotEmpty) {
      TreeNode current = queue.removeFirst();

      TreeNode? temp = current.left;
      current.left = current.right;
      current.right = temp;

      if (current.left != null) {
        queue.add(current.left!);
      }
      if (current.right != null) {
        queue.add(current.right!);
      }
    }

    return root;
  }
}
