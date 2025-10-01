import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class MaximumDepthOfBinaryTree {
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

  private record NodeDepthRecord(TreeNode node, int depth) {
  }

  /**
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  public int maxDepth(TreeNode root) {
    if (root == null) {
      return 0;
    }

    int left = maxDepth(root.left);
    int right = maxDepth(root.right);

    return Math.max(left, right) + 1;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Recursion: DFS
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  public int solution1(TreeNode root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = maxDepth(root.left);
    int rightDepth = maxDepth(root.right);

    return Math.max(leftDepth, rightDepth) + 1;
  }

  /**
   * Solution 2
   * 
   * Iteration: BFS (Queue)
   * - Time Complexity: O(N)
   * - Space Complexity: O(W)
   */
  public int solution2(TreeNode root) {
    if (root == null) {
      return 0;
    }

    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    int depth = 0;

    while (!queue.isEmpty()) {
      int levelSize = queue.size();
      depth++;

      for (int i = 0; i < levelSize; i++) {
        TreeNode currentNode = queue.poll();

        if (currentNode.left != null) {
          queue.offer(currentNode.left);
        }
        if (currentNode.right != null) {
          queue.offer(currentNode.right);
        }
      }
    }

    return depth;
  }

  /**
   * Solution 3
   * 
   * Iteration: DFS (Stack)
   * - Time Complexity: O(N)
   * - Space Complexity: O(H)
   */
  public int solution3(TreeNode root) {
    if (root == null) {
      return 0;
    }

    Stack<NodeDepthRecord> stack = new Stack<>();
    stack.push(new NodeDepthRecord(root, 1));

    int maxDepth = 0;

    while (!stack.isEmpty()) {
      NodeDepthRecord currentPair = stack.pop();
      TreeNode currentNode = currentPair.node;
      int currentDepth = currentPair.depth;

      maxDepth = Math.max(maxDepth, currentDepth);

      if (currentNode.right != null) {
        stack.push(new NodeDepthRecord(currentNode.right, currentDepth + 1));
      }
      if (currentNode.left != null) {
        stack.push(new NodeDepthRecord(currentNode.left, currentDepth + 1));
      }
    }

    return maxDepth;
  }
}
