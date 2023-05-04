import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BinaryTreeInorderTraversal {

  public class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
      this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }

  public List<Integer> inorderTraversal(TreeNode root) {
    List<TreeNode> totalRoot = new ArrayList<TreeNode>();
    List<Integer> result = new ArrayList<Integer>();

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

  // Best Solution
  public List<Integer> bestSolution(TreeNode root) {
    List<Integer> list = new ArrayList<Integer>();

    Stack<TreeNode> stack = new Stack<TreeNode>();
    TreeNode cur = root;

    while (cur != null || !stack.empty()) {
      while (cur != null) {
        stack.add(cur);
        cur = cur.left;
      }
      cur = stack.pop();
      list.add(cur.val);
      cur = cur.right;
    }

    return list;
  }
}
