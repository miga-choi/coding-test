import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

class BinaryTreePostorderTraversal {
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
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  public List<Integer> postorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    List<TreeNode> nodes = new ArrayList<>();

    if (root != null) {
      nodes.add(root);

      while (!nodes.isEmpty()) {
        TreeNode node = nodes.remove(nodes.size() - 1);
        result.add(node.val);

        if (node.left != null) {
          nodes.add(node.left);
        }

        if (node.right != null) {
          nodes.add(node.right);
        }
      }
    }

    Collections.reverse(result);
    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Recursion
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  public List<Integer> solution1(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    traverse(root, result);
    return result;
  }

  private void traverse(TreeNode node, List<Integer> result) {
    if (node == null) {
      return;
    }

    traverse(node.left, result);

    traverse(node.right, result);

    result.add(node.val);
  }

  /**
   * Solution 2
   *
   * Iteration
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   H - Height of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(H)
   */
  public List<Integer> solution2(TreeNode root) {
    LinkedList<Integer> result = new LinkedList<>();

    if (root == null) {
      return result;
    }

    Stack<TreeNode> stack = new Stack<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      TreeNode curr = stack.pop();

      result.addFirst(curr.val);

      if (curr.left != null) {
        stack.push(curr.left);
      }
      if (curr.right != null) {
        stack.push(curr.right);
      }
    }

    return result;
  }
}
