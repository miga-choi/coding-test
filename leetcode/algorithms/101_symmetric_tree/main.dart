import 'dart:collection';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SymmetricTree {
  /**
   * Recursion - DFS
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  bool isSymmetric(TreeNode? root) {
    if (root == null) {
      return true;
    }

    bool checkSymmetric(TreeNode? p, TreeNode? q) {
      if (p == null && q == null) {
        return true;
      }

      if (p != null && q != null) {
        return checkSymmetric(p.left, q.right) &&
            checkSymmetric(p.right, q.left) &&
            p.val == q.val;
      }

      return false;
    }

    return checkSymmetric(root.left, root.right);
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
  bool solution1(TreeNode? root) {
    if (root == null) {
      return true;
    }

    return _isMirror(root.left, root.right);
  }

  bool _isMirror(TreeNode? t1, TreeNode? t2) {
    if (t1 == null && t2 == null) {
      return true;
    }

    if (t1 == null || t2 == null) {
      return false;
    }

    if (t1.val != t2.val) {
      return false;
    }

    return _isMirror(t1.left, t2.right) && _isMirror(t1.right, t2.left);
  }

  /**
   * Solution 2
   *
   * Iteration
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  bool solution2(TreeNode? root) {
    if (root == null) {
      return true;
    }

    Queue<TreeNode?> queue = Queue();

    queue.add(root.left);
    queue.add(root.right);

    while (queue.isNotEmpty) {
      TreeNode? t1 = queue.removeFirst();
      TreeNode? t2 = queue.removeFirst();

      if (t1 == null && t2 == null) {
        continue;
      }

      if (t1 == null || t2 == null || t1.val != t2.val) {
        return false;
      }

      queue.add(t1.left);
      queue.add(t2.right);

      queue.add(t1.right);
      queue.add(t2.left);
    }

    return true;
  }
}
