import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class MaximumDepthOfBinaryTree {
  int maxDepth(TreeNode? root) {
    int returnDepth(TreeNode? node, int depth) {
      if (node == null) {
        return depth;
      }
      return 1 + max(returnDepth(node.left, depth), returnDepth(node.right, depth));
    }

    return returnDepth(root, 0);
  }

  // Best Solution
  int bestSolution(TreeNode? root) {
    return visiter(root);
  }

  int visiter(TreeNode? root) {
    if (root == null) return 0;
    int sum = 1;

    final leftSum = visiter(root.left);
    final rightSum = visiter(root.right);

    return sum + max(leftSum, rightSum);
  }
}
