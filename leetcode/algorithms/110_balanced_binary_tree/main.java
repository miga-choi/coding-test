import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class BalancedBinaryTree {
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

  public boolean isBalanced(TreeNode root) {
    return checkDepth(root) > -1;
  }

  public int checkDepth(TreeNode node_) {
    if (node_ == null) {
      return 0;
    }

    int leftDepth = checkDepth(node_.left);
    int rightDepth = checkDepth(node_.right);

    if (leftDepth == -1 ||
        rightDepth == -1 ||
        Math.abs(leftDepth - rightDepth) > 1) {
      return -1;
    }

    return Math.max(leftDepth, rightDepth) + 1;
  }


  // Solution
  // Solution 1
  public boolean solution1(TreeNode root) {
    // If the tree is empty, we can say it’s balanced...
    if (root == null) {
      return true;
    }
    // Height Function will return -1, when it’s an unbalanced tree...
    if (solution1_height(root) == -1) {
      return false;
    }
    return true;
  }

  // Create a function to return the “height” of a current subtree using recursion...
  public int solution1_height(TreeNode root) {
    // Base case...
    if (root == null) {
      return 0;
    }
    // Height of left subtree...
    int leftHeight = solution1_height(root.left);
    // Height of height subtree...
    int rightHight = solution1_height(root.right);
    // In case of left subtree or right subtree unbalanced, return -1...
    if (leftHeight == -1 || rightHight == -1) {
      return -1;
    }
    // If their heights differ by more than ‘1’, return -1...
    if (Math.abs(leftHeight - rightHight) > 1) {
      return -1;
    }
    // Otherwise, return the height of this subtree as max(leftHeight, rightHight) + 1...
    return Math.max(leftHeight, rightHight) + 1;
  }

  // Solution 2: Iterative PostOrder Traversal
  public boolean solution2(TreeNode root) {
    if (root == null) {
      return true;
    }
    Stack<TreeNode> stack = new Stack<TreeNode>();
    Map<TreeNode, Integer> map = new HashMap<TreeNode, Integer>();
    stack.push(root);
    while (!stack.isEmpty()) {
      TreeNode node = stack.pop();
      if ((node.left == null || node.left != null && map.containsKey(node.left))
          && (node.right == null || node.right != null && map.containsKey(node.right))) {
        int left = node.left == null ? 0 : map.get(node.left);
        int right = node.right == null ? 0 : map.get(node.right);
        if (Math.abs(left - right) > 1) {
          return false;
        }
        map.put(node, Math.max(left, right) + 1);
      } else {
        if (node.left != null && !map.containsKey(node.left)) {
          stack.push(node);
          stack.push(node.left);
        } else {
          stack.push(node);
          stack.push(node.right);
        }
      }
    }
    return true;
  }
}
