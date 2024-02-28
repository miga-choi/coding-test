import java.util.Stack;

class SymmetricTree {
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

  public boolean isSymmetric(TreeNode root) {
    if (root == null) {
      return true;
    }
    return checkNode(root.left, root.right);
  }

  private boolean checkNode(TreeNode leftNode, TreeNode rightNode) {
    if (leftNode == null && rightNode == null) {
      return true;
    }
    if ((leftNode == null && rightNode != null) ||
        (leftNode != null && rightNode == null)) {
      return false;
    }
    if (leftNode != null && rightNode != null) {
      if (leftNode.val != rightNode.val) {
        return false;
      } else {
        return (checkNode(leftNode.left, rightNode.right) &&
            checkNode(leftNode.right, rightNode.left));
      }
    }
    return false;
  }


  // Best Solution
  // Best Solution 1: Recursive
  public boolean bestSolution1(TreeNode root) {
    return root == null || bestSolution1_isSymmetricHelp(root.left, root.right);
  }

  private boolean bestSolution1_isSymmetricHelp(TreeNode left, TreeNode right) {
    if (left == null || right == null) {
      return left == right;
    }

    if (left.val != right.val) {
      return false;
    }

    return (bestSolution1_isSymmetricHelp(left.left, right.right) &&
        bestSolution1_isSymmetricHelp(left.right, right.left));
  }

  // Best Solution 2: Non-recursive (use Stack):
  public boolean bestSolution2(TreeNode root) {
    if (root == null) {
      return true;
    }

    Stack<TreeNode> stack = new Stack<TreeNode>();
    TreeNode left, right;

    if (root.left != null) {
      if (root.right == null) {
        return false;
      }
      stack.push(root.left);
      stack.push(root.right);
    } else if (root.right != null) {
      return false;
    }

    while (!stack.empty()) {
      if (stack.size() % 2 != 0) {
        return false;
      }

      right = stack.pop();
      left = stack.pop();

      if (right.val != left.val) {
        return false;
      }

      if (left.left != null) {
        if (right.right == null) {
          return false;
        }
        stack.push(left.left);
        stack.push(right.right);
      } else if (right.right != null) {
        return false;
      }

      if (left.right != null) {
        if (right.left == null) {
          return false;
        }
        stack.push(left.right);
        stack.push(right.left);
      } else if (right.left != null) {
        return false;
      }
    }

    return true;
  }
}
