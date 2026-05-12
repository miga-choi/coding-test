import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class BinaryTreePreorderTraversal {
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
  public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    List<TreeNode> nodes = new ArrayList<>();

    if (root != null) {
      nodes.add(root);

      while (!nodes.isEmpty()) {
        TreeNode node = nodes.remove(nodes.size() - 1);
        result.add(node.val);

        if (node.right != null) {
          nodes.add(node.right);
        }

        if (node.left != null) {
          nodes.add(node.left);
        }
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

    result.add(node.val);

    traverse(node.left, result);

    traverse(node.right, result);
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
    List<Integer> result = new ArrayList<>();

    if (root == null) {
      return result;
    }

    Stack<TreeNode> stack = new Stack<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      TreeNode currentNode = stack.pop();
      result.add(currentNode.val);

      if (currentNode.right != null) {
        stack.push(currentNode.right);
      }
      if (currentNode.left != null) {
        stack.push(currentNode.left);
      }
    }

    return result;
  }
}
