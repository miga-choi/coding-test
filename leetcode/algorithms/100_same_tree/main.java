import java.util.LinkedList;
import java.util.Queue;

class SameTree {
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
      this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }

  /**
   * Recursion - DFS
   *
   * Complexities:
   *   M - The number of nodes in `p`
   *   N - The number of nodes in `q`
   *   H𝗉 - The heights of `p`
   *   H𝗊 - The heights of `q`
   *   - Time Complexity: O(min(M, N))
   *   - Space Complexity: O(min(H𝗉, H𝗊))
   */
  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null) {
      return true;
    }

    if (p == null || q == null || p.val != q.val) {
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
   *   H𝗉 - The heights of `p`
   *   H𝗊 - The heights of `q`
   *   - Time Complexity: O(min(M, N))
   *   - Space Complexity: O(min(H𝗉, H𝗊))
   */
  public boolean solution1(TreeNode p, TreeNode q) {
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
   *   H𝗉 - The heights of `p`
   *   H𝗊 - The heights of `q`
   *   - Time Complexity: O(min(M, N))
   *   - Space Complexity: O(min(H𝗉, H𝗊))
   */
  public boolean solution2(TreeNode p, TreeNode q) {
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(p);
    queue.add(q);

    while (!queue.isEmpty()) {
      TreeNode nodeP = queue.poll();
      TreeNode nodeQ = queue.poll();

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
