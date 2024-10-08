import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BalancedBinaryTree {
  bool isBalanced(TreeNode? root) {
    if (root == null) {
      return true;
    }

    int returnDepth(TreeNode? node) {
      if (node == null) {
        return 0;
      }
      return max(returnDepth(node.left), returnDepth(node.right)) + 1;
    }

    if ((returnDepth(root.left) - returnDepth(root.right)).abs() > 1) {
      return false;
    }

    return isBalanced(root.left) && isBalanced(root.right);
  }

  // Best Solution
  bool bestSolution(TreeNode? root) {
    return cnt(root) != -1;
  }

  int cnt(TreeNode? nod) {
    if (nod == null) return 0;
    int l = cnt(nod.left);
    if (l == -1) return -1;
    int r = cnt(nod.right);
    if (r == -1) return -1;
    if ((r - l > 1) || (l - r > 1)) return -1;
    return (l >= r ? l + 1 : r + 1);
  }
}
