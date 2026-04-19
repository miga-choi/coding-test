import java.util.LinkedList;
import java.util.Queue;

class PathSum {
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
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public boolean hasPathSum(TreeNode root, int targetSum) {
    if (root == null) {
      return false;
    }

    if (root.left == null && root.right == null) {
      return root.val == targetSum;
    }

    return (hasPathSum(root.left, targetSum - root.val) || hasPathSum(root.right, targetSum - root.val));
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursion - DFS
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public boolean solution1(TreeNode root, int targetSum) {
    if (root == null) {
      return false;
    }

    if (root.left == null && root.right == null) {
      return targetSum == root.val;
    }

    int remainingSum = targetSum - root.val;
    return solution1(root.left, remainingSum) || solution1(root.right, remainingSum);
  }

  /**
   * Solution 2
   *
   * Iteration - BFS with Queue
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public boolean solution2(TreeNode root, int targetSum) {
    if (root == null) {
      return false;
    }

    Queue<TreeNode> nodeQueue = new LinkedList<>();
    Queue<Integer> sumQueue = new LinkedList<>();

    nodeQueue.offer(root);
    sumQueue.offer(root.val);

    while (!nodeQueue.isEmpty()) {
      TreeNode currentNode = nodeQueue.poll();
      int currentSum = sumQueue.poll();

      if (currentNode.left == null && currentNode.right == null && currentSum == targetSum) {
        return true;
      }

      if (currentNode.left != null) {
        nodeQueue.offer(currentNode.left);
        sumQueue.offer(currentSum + currentNode.left.val);
      }

      if (currentNode.right != null) {
        nodeQueue.offer(currentNode.right);
        sumQueue.offer(currentSum + currentNode.right.val);
      }
    }

    return false;
  }
}
