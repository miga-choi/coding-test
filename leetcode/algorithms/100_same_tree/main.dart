import 'dart:collection';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SameTree {
  /**
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  bool isSameTree(TreeNode? p, TreeNode? q) {
    if (p == null && q == null) {
      return true;
    }

    if (p == null || q == null || q.val != q.val) {
      return false;
    }

    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
  }


  // Solution
  /**
   * Solution 1
   * 
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  bool solution1(TreeNode? p, TreeNode? q) {
    if (p == null && q == null) {
      return true;
    }

    if (p == null || q == null || p.val != q.val) {
      return false;
    }

    return solution1(p.left, q.left) && solution1(p.right, q.right);
  }

  /**
   * Solution 2
   * 
   * Iteration: DFS (Stack)
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  bool solution2(TreeNode? p, TreeNode? q) {
    List<TreeNode?> stackP = [];
    List<TreeNode?> stackQ = [];

    stackP.add(p);
    stackQ.add(q);

    while (stackP.isNotEmpty) {
      TreeNode? nodeP = stackP.removeLast();
      TreeNode? nodeQ = stackQ.removeLast();

      if (nodeP == null && nodeQ == null) {
        continue;
      }

      if (nodeP == null || nodeQ == null || nodeP.val != nodeQ.val) {
        return false;
      }

      stackP.add(nodeP.left);
      stackQ.add(nodeQ.left);

      stackP.add(nodeP.right);
      stackQ.add(nodeQ.right);
    }

    return true;
  }

  /**
   * Solution 3
   * 
   * Iteration: BFS (Queue)
   * - Time Complexity: O(N)
   * - Space Complexity: O(W)
   */
  bool solution3(TreeNode? p, TreeNode? q) {
    Queue<TreeNode?> queue = Queue();
    queue.add(p);
    queue.add(q);

    while (queue.isNotEmpty) {
      TreeNode? node1 = queue.removeFirst();
      TreeNode? node2 = queue.removeFirst();

      if (node1 == null && node2 == null) {
        continue;
      }

      if (node1 == null || node2 == null || node1.val != node2.val) {
        return false;
      }

      queue.add(node1.left);
      queue.add(node2.left);
      queue.add(node1.right);
      queue.add(node2.right);
    }

    return true;
  }
}
