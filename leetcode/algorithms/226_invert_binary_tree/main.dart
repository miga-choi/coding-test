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
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
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
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  TreeNode? solution1(TreeNode? root) {
    if (root == null) {
      return null;
    }

    solution1(root.left);
    solution1(root.right);

    TreeNode? temp = root.left;
    root.left = root.right;
    root.right = temp;

    return root;
  }

  /**
   * Solution 2
   * 
   * Iteration: BFS (Queue)
   * - Time Complexity: O(N)
   * - Space Complexity: O(W)
   */
  TreeNode? solution2(TreeNode? root) {
    if (root == null) {
      return null;
    }

    Queue<TreeNode> queue = Queue();
    queue.add(root);

    while (queue.isNotEmpty) {
      TreeNode currentNode = queue.removeFirst();

      TreeNode? temp = currentNode.left;
      currentNode.left = currentNode.right;
      currentNode.right = temp;

      if (currentNode.left != null) {
        queue.add(currentNode.left!);
      }
      if (currentNode.right != null) {
        queue.add(currentNode.right!);
      }
    }

    return root;
  }
}
