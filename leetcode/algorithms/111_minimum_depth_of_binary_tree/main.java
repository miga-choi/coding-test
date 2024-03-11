import java.util.LinkedList;
import java.util.Queue;

class MinimumDepthOfBinaryTree {
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

  public int minDepth(TreeNode root) {
    if (root == null) {
      return 0;
    }

    if (root.left == null && root.right == null) {
      return 1;
    }

    if (root.left == null) {
      return minDepth(root.right) + 1;
    }

    if (root.right == null) {
      return minDepth(root.left) + 1;
    }

    return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
  }


  // Best Solution
  // Best Solution 1:
  public int bestSolution1(TreeNode root) {
    if (root == null) {
      return 0;
    }
    int left = bestSolution1(root.left);
    int right = bestSolution1(root.right);
    return (left == 0 || right == 0)
        ? left + right + 1
        : Math.min(left, right) + 1;
  }

  // Best Solution 2:
  public int bestSolution2(TreeNode root) {
    // Base case...
    // If the subtree is empty i.e. root is NULL, return depth as 0...
    if (root == null) {
      return 0;
    }

    // Initialize the depth of two subtrees...
    int leftDepth = bestSolution2(root.left);
    int rightDepth = bestSolution2(root.right);

    // If the both subtrees are empty...
    if (root.left == null && root.right == null) {
      return 1;
    }

    // If the left subtree is empty, return the depth of right subtree
    // after adding 1 to it...
    if (root.left == null) {
      return rightDepth + 1;
    }

    // If the right subtree is empty, return the depth of left subtree
    // after adding 1 to it...
    if (root.right == null) {
      return leftDepth + 1;
    }

    // When the two child function return its depth...
    // Pick the minimum out of these two subtrees
    // and return this value after adding 1 to it...
    // Adding 1 is the current node which is the parent of the two subtrees...
    return Math.min(leftDepth, rightDepth) + 1;
  }

  // Best Solution 3: BFS
  public int bestSolution3(TreeNode root) {
    if (root == null) {
      return 0;
    }
    int depth = 1;
    Queue<TreeNode> q = new LinkedList<TreeNode>();
    q.offer(root);
    while (!q.isEmpty()) {
      int size = q.size();
      // for each level
      for (int i = 0; i < size; i++) {
        TreeNode node = q.poll();
        if (node.left == null && node.right == null) {
          return depth;
        }
        if (node.left != null) {
          q.offer(node.left);
        }
        if (node.right != null) {
          q.offer(node.right);
        }
      }
      depth++;
    }
    return depth;
  }
}
