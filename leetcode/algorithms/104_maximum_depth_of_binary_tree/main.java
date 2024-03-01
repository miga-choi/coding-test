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

  public int maxDepth(TreeNode root) {
    if (root == null) {
      return 0;
    }
    return returnDepth(0, root);
  }

  public int returnDepth(int depth_, TreeNode node_) {
    int depth = depth_ + 1;
    if (node_.left != null) {
      int leftDepth = returnDepth(depth_ + 1, node_.left);
      if (leftDepth > depth) {
        depth = leftDepth;
      }
    }
    if (node_.right != null) {
      int rightDepth = returnDepth(depth_ + 1, node_.right);
      if (rightDepth > depth) {
        depth = rightDepth;
      }
    }
    return depth;
  }


  // Best Solution
  // Best Solution 1: Recursive
  public int bestSolution1(TreeNode root) {
    // Base Condition
    if (root == null) {
      return 0;
    }
    // Hypothesis
    int left = bestSolution1(root.left);
    int right = bestSolution1(root.right);
    // Induction
    return Math.max(left, right) + 1;
  }

  // Best Solution 2: Iterative - DFS
  public int bestSolution2(TreeNode root) {
    if (root == null) {
      return 0;
    }

    Stack<TreeNode> stack = new Stack<>();
    Stack<Integer> value = new Stack<>();
    stack.push(root);
    value.push(1);
    int max = 0;
    while (!stack.isEmpty()) {
      TreeNode node = stack.pop();
      int temp = value.pop();
      max = Math.max(temp, max);
      if (node.left != null) {
        stack.push(node.left);
        value.push(temp + 1);
      }
      if (node.right != null) {
        stack.push(node.right);
        value.push(temp + 1);
      }
    }
    return max;
  }

  // Best Solution 3: Iterative - BFS
  public int bestSolution3(TreeNode root) {
    if (root == null) {
      return 0;
    }
    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    queue.offer(root);
    int count = 0;
    while (!queue.isEmpty()) {
      int size = queue.size();
      while (size-- > 0) {
        TreeNode node = queue.poll();
        if (node.left != null) {
          queue.offer(node.left);
        }
        if (node.right != null) {
          queue.offer(node.right);
        }
      }
      count++;
    }
    return count;
  }
}
