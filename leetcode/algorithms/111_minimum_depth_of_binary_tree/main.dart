import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class Solution {
  int minDepth(TreeNode? root) {
    if (root == null) {
      return 0;
    }

    int leftDepth = minDepth(root.left);
    int rightDepth = minDepth(root.right);

    if (leftDepth == 0 && rightDepth == 0) {
      return 1;
    } else if (leftDepth == 0) {
      return rightDepth + 1;
    } else if (rightDepth == 0) {
      return leftDepth + 1;
    }

    return min(leftDepth, rightDepth) + 1;
  }

  // Solution
  int solution(TreeNode? root) {
    if (root == null) {
      return 0;
    }
    int l = solution(root.left);
    int r = solution(root.right);
    if (l == 0 || r == 0) {
      return l + r + 1;
    }
    return min(l, r) + 1;
  }
}
