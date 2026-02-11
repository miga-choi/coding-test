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
   *
   * Complexities:
   * N - Size of `root`
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
   *
   * Complexities:
   *   N - Size of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  private void helper(TreeNode node, List<Integer> list) {
    if (node == null) {
      return;
    }

    helper(node.left, list);

    list.add(node.val);

    helper(node.right, list);
  }

  public List<Integer> solution1(TreeNode root) {
    List<Integer> result = new ArrayList<>();

    helper(root, result);

    return result;
  }

  /**
   * Solution 2
   *
   * Iteration
   *
   * Complexities:
   *   N - Size of `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public List<Integer> solution2(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    TreeNode curr = root;

    while (curr != null || !stack.isEmpty()) {
      while (curr != null) {
        stack.push(curr);
        curr = curr.left;
      }

      curr = stack.pop();

      result.add(curr.val);

      curr = curr.right;
    }

    return result;
  }
}
