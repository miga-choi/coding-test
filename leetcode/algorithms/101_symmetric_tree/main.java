import java.util.LinkedList;
import java.util.Queue;

class SymmetricTree {
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
   *   N - The number of nodes in `root`
   *   H - The heights of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  public boolean isSymmetric(TreeNode root) {
    if (root == null) {
      return true;
    }
    return checkNode(root.left, root.right);
  }

  private boolean checkNode(TreeNode leftNode, TreeNode rightNode) {
    if (leftNode == null && rightNode == null) {
      return true;
    }
    if ((leftNode == null && rightNode != null) ||
        (leftNode != null && rightNode == null)) {
      return false;
    }
    if (leftNode != null && rightNode != null) {
      if (leftNode.val != rightNode.val) {
        return false;
      } else {
        return (checkNode(leftNode.left, rightNode.right) &&
            checkNode(leftNode.right, rightNode.left));
      }
    }
    return false;
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
  public boolean solution1(TreeNode root) {
    if (root == null) {
      return true;
    }

    return isMirror(root.left, root.right);
  }

  private boolean isMirror(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) {
      return true;
    }

    if (t1 == null || t2 == null) {
      return false;
    }

    if (t1.val != t2.val) {
      return false;
    }

    return isMirror(t1.left, t2.right) && isMirror(t1.right, t2.left);
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
  public boolean solution2(TreeNode root) {
    if (root == null) {
      return true;
    }

    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root.left);
    queue.add(root.right);

    while (!queue.isEmpty()) {
      TreeNode t1 = queue.poll();
      TreeNode t2 = queue.poll();

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
