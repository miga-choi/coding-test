import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

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
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
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
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  public boolean solution1(TreeNode p, TreeNode q) {
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
  public boolean solution2(TreeNode p, TreeNode q) {
    Stack<TreeNode> stack = new Stack<>();

    stack.push(p);
    stack.push(q);

    while (!stack.isEmpty()) {
      TreeNode nodeQ = stack.pop();
      TreeNode nodeP = stack.pop();

      if (nodeP == null && nodeQ == null) {
        continue;
      }

      if (nodeP == null || nodeQ == null || nodeP.val != nodeQ.val) {
        return false;
      }

      stack.push(nodeP.left);
      stack.push(nodeQ.left);
      stack.push(nodeP.right);
      stack.push(nodeQ.right);
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
  public boolean solution3(TreeNode p, TreeNode q) {
    Queue<TreeNode> queue = new LinkedList<>();

    queue.offer(p);
    queue.offer(q);

    while (!queue.isEmpty()) {
      TreeNode nodeP = queue.poll();
      TreeNode nodeQ = queue.poll();

      if (nodeP == null && nodeQ == null) {
        continue;
      }

      if (nodeP == null || nodeQ == null || nodeP.val != nodeQ.val) {
        return false;
      }

      queue.offer(nodeP.left);
      queue.offer(nodeQ.left);
      queue.offer(nodeP.right);
      queue.offer(nodeQ.right);
    }

    return true;
  }
}
