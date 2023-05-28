import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

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

class TreeNode {

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

class Solution {

  public List<Integer> postorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<Integer>();
    List<TreeNode> nodes = new ArrayList<TreeNode>();

    if (root != null) {
      nodes.add(root);

      while (nodes.size() > 0) {
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

  // Best Solution
  // Pre Order Traverse
  public List<Integer> preOrderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while (!stack.isEmpty() || p != null) {
      if (p != null) {
        stack.push(p);
        result.add(p.val); // Add before going to children
        p = p.left;
      } else {
        TreeNode node = stack.pop();
        p = node.right;
      }
    }
    return result;
  }

  // In Order Traverse
  public List<Integer> inOrderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while (!stack.isEmpty() || p != null) {
      if (p != null) {
        stack.push(p);
        p = p.left;
      } else {
        TreeNode node = stack.pop();
        result.add(node.val); // Add after all left children
        p = node.right;
      }
    }
    return result;
  }

  // Post Order Traverse
  public List<Integer> postOrderTraversal(TreeNode root) {
    LinkedList<Integer> result = new LinkedList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while (!stack.isEmpty() || p != null) {
      if (p != null) {
        stack.push(p);
        result.addFirst(p.val); // Reverse the process of preorder
        p = p.right; // Reverse the process of preorder
      } else {
        TreeNode node = stack.pop();
        p = node.left; // Reverse the process of preorder
      }
    }
    return result;
  }
}
