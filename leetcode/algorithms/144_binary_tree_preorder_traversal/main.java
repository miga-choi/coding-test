import java.util.ArrayList;
import java.util.LinkedList;
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

  public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<Integer>();
    List<TreeNode> nodes = new ArrayList<TreeNode>();

    if (root != null) {
      nodes.add(root);

      while (nodes.size() > 0) {
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
  // Solution 1: Recursive method with List as returning value:
  public List<Integer> solution1(TreeNode root) {
    List<Integer> pre = new LinkedList<Integer>();
    if (root == null) {
      return pre;
    }
    pre.add(root.val);
    pre.addAll(preorderTraversal(root.left));
    pre.addAll(preorderTraversal(root.right));
    return pre;
  }

  // Solution 2: Recursive method with Helper
  // Recursive method with Helper method to have a List as paramater,
  // so we can modify the parameter and don't have to instantiate a new List at
  // each recursive call:
  public List<Integer> solution2(TreeNode root) {
    List<Integer> pre = new LinkedList<Integer>();
    preHelper(root, pre);
    return pre;
  }

  public void preHelper(TreeNode root, List<Integer> pre) {
    if (root == null) {
      return;
    }
    pre.add(root.val);
    preHelper(root.left, pre);
    preHelper(root.right, pre);
  }

  // Solution 3: Iterative method with Stack:
  public List<Integer> solution3(TreeNode root) {
    List<Integer> pre = new LinkedList<Integer>();
    if (root == null) {
      return pre;
    }
    Stack<TreeNode> tovisit = new Stack<TreeNode>();
    tovisit.push(root);
    while (!tovisit.empty()) {
      TreeNode visiting = tovisit.pop();
      pre.add(visiting.val);
      if (visiting.right != null) {
        tovisit.push(visiting.right);
      }
      if (visiting.left != null) {
        tovisit.push(visiting.left);
      }
    }
    return pre;
  }
}
