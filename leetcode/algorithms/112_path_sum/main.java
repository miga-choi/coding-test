import java.util.Stack;

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

  public boolean hasPathSum(TreeNode root, int targetSum) {
    if (root == null) {
      return false;
    }
    if (root.left == null && root.right == null) {
      return root.val == targetSum;
    } else {
      return (hasPathSum(root.left, targetSum - root.val) ||
          hasPathSum(root.right, targetSum - root.val));
    }
  }


  // Solution
  // Solution 1: Recursion
  public boolean solution1(TreeNode root, int sum) {
    if (root == null) {
      return false;
    }

    if (root.left == null && root.right == null && sum - root.val == 0) {
      return true;
    }

    return solution1(root.left, sum - root.val) || solution1(root.right, sum - root.val);
  }

  // Solution 2: Iteration
  public boolean solution2(TreeNode root, int sum) {
    // iteration method
    if (root == null) {
      return false;
    }
    Stack<TreeNode> path = new Stack<>();
    Stack<Integer> sub = new Stack<>();
    path.push(root);
    sub.push(root.val);
    while (!path.isEmpty()) {
      TreeNode temp = path.pop();
      int tempVal = sub.pop();
      if (temp.left == null && temp.right == null) {
        if (tempVal == sum) {
          return true;
        }
      } else {
        if (temp.left != null) {
          path.push(temp.left);
          sub.push(temp.left.val + tempVal);
        }
        if (temp.right != null) {
          path.push(temp.right);
          sub.push(temp.right.val + tempVal);
        }
      }
    }
    return false;
  }

  // Solution 3: Recursion
  public boolean solution3(TreeNode root, int sum) {
    // recursion method
    if (root == null) {
      return false;
    }
    if (root.left == null && root.right == null && root.val == sum) {
      return true;
    }
    return (solution3(root.left, sum - root.val) ||
        solution3(root.right, sum - root.val));
  }
}
