import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class DiameterOfBinaryTree {
  int diameterOfBinaryTree(TreeNode? root) {
    int n = 0;

    int returnDepth(TreeNode? node) {
      if (node == null) {
        return 0;
      }

      int left = returnDepth(node.left);
      int right = returnDepth(node.right);

      if (left + right > n) {
        n = left + right;
      }

      return max(left, right) + 1;
    }

    returnDepth(root);

    return n;
  }

  // Solution
  // Member variable to store the diameter
  int diameter = 0;

  int helper(TreeNode? node) {
    // Base case: if node is null, return 0
    if (node == null) {
      return 0;
    }

    // Get depth of left subtree
    int leftDepth = helper(node.left);

    // Get depth of right subtree
    int rightDepth = helper(node.right);

    // Calculate diameter at this node (number of edges)
    int currentDiameter = leftDepth + rightDepth;

    // Update the maximum diameter found so far
    diameter = max(diameter, currentDiameter);

    // Return the depth of this subtree
    return max(leftDepth, rightDepth) + 1;
  }

  int solution(TreeNode? root) {
    helper(root);

    // Return the calculated diameter
    return diameter;
  }
}
