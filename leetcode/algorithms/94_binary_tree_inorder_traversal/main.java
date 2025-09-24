import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class BinaryTreeInorderTraversal {
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
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  public List<Integer> inorderTraversal(TreeNode root) {
    List<TreeNode> totalRoot = new ArrayList<>();
    List<Integer> result = new ArrayList<>();

    while (root != null || !totalRoot.isEmpty()) {
      if (root != null) {
        totalRoot.add(root);
        root = root.left;
      } else {
        root = totalRoot.remove(totalRoot.size() - 1);
        result.add(root.val);
        root = root.right;
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Recursion
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  private void inorderRecursive(TreeNode node, List<Integer> result) {
    if (node == null) {
      return;
    }

    inorderRecursive(node.left, result);
    result.add(node.val);
    inorderRecursive(node.right, result);
  }

  public List<Integer> solution1(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    inorderRecursive(root, result);
    return result;
  }

  /**
   * Solution 2
   * 
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  public List<Integer> solution2(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    TreeNode current = root;

    while (current != null || !stack.isEmpty()) {
      while (current != null) {
        stack.push(current);
        current = current.left;
      }

      current = stack.pop();
      result.add(current.val);
      current = current.right;
    }

    return result;
  }

  /**
   * Solution 2
   * 
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  public List<Integer> solution3(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    TreeNode current = root;

    while (current != null) {
      if (current.left == null) {
        result.add(current.val);
        current = current.right;
      } else {
        TreeNode predecessor = current.left;

        while (predecessor.right != null && predecessor.right != current) {
          predecessor = predecessor.right;
        }

        if (predecessor.right == null) {
          predecessor.right = current;
          current = current.left;
        } else {
          predecessor.right = null;
          result.add(current.val);
          current = current.right;
        }
      }
    }

    return result;
  }
}
