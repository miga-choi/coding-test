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
   * Recursion - DFS
   *
   * Complexities:
   *   M - The number of nodes in `p`
   *   N - The number of nodes in `q`
   *   Hp - The heights of `p`
   *   Hq - The heights of `q`
   *   - Time Complexity: O(min(M, N))
   *   - Space Complexity: O(min(Hp, Hq))
   */
  bool solution1(TreeNode? p, TreeNode? q) {
    if (p == null && q == null) {
      return true;
    }

    if (p == null || q == null) {
      return false;
    }

    if (p.val != q.val) {
      return false;
    }

    return solution1(p.left, q.left) && solution1(p.right, q.right);
  }

  /**
   * Solution 2
   *
   * Iteration - BFS
   *
   * Complexities:
   *   M - The number of nodes in `p`
   *   N - The number of nodes in `q`
   *   Hp - The heights of `p`
   *   Hq - The heights of `q`
   *   - Time Complexity: O(min(M, N))
   *   - Space Complexity: O(min(Hp, Hq))
   */
  bool solution2(TreeNode? p, TreeNode? q) {
    Queue<TreeNode?> queue = Queue();
    queue.add(p);
    queue.add(q);

    while (queue.isNotEmpty) {
      TreeNode? nodeP = queue.removeFirst();
      TreeNode? nodeQ = queue.removeFirst();

      if (nodeP == null && nodeQ == null) {
        continue;
      }

      if (nodeP == null || nodeQ == null || nodeP.val != nodeQ.val) {
        return false;
      }

      queue.add(nodeP.left);
      queue.add(nodeQ.left);
      queue.add(nodeP.right);
      queue.add(nodeQ.right);
    }

    return true;
  }
}
