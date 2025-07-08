import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class MinimumDistanceBetweenBSTNodes {
  void inorderTraversal(TreeNode? node, List<int> vals) {
    if (node == null) {
      return;
    }

    inorderTraversal(node.left, vals);
    vals.add(node.val);
    inorderTraversal(node.right, vals);
  }

  int minDiffInBST(TreeNode? root) {
    List<int> vals = List<int>.empty(growable: true);

    inorderTraversal(root, vals);

    int min = pow(10, 5).floor();

    for (int i = 0; i < vals.length - 1; i++) {
      int diff = vals[i + 1] - vals[i];
      if (diff < min) {
        min = diff;
      }
    }

    return min;
  }


  // Solution
  int res = double.maxFinite.floor(), pre = -1;

  int solution(TreeNode? root) {
    if (root != null) {
      if (root.left != null) {
        minDiffInBST(root.left);
      }

      if (pre >= 0) {
        res = min(res, root.val - pre);
      }

      pre = root.val;

      if (root.right != null) {
        minDiffInBST(root.right);
      }
    }

    return res;
  }
}
