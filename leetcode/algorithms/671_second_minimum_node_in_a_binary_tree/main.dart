import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SecondMinimumNodeInABinaryTree {
  int returnSecondMinimumValue(TreeNode? node, int minVal) {
    if (node == null) {
      return -1;
    }

    if (node.val > minVal) {
      return node.val;
    }

    int left = returnSecondMinimumValue(node.left, node.val);
    int right = returnSecondMinimumValue(node.right, node.val);

    if (left == -1) {
      return right;
    }
    if (right == -1) {
      return left;
    }

    return min(left, right);
  }

  int findSecondMinimumValue(TreeNode? root) {
    return returnSecondMinimumValue(root, root!.val);
  }

  // Solution
  int solution(TreeNode? root) {
    List<int> res = [];

    void helper(TreeNode? node) {
      if (node == null) return;
      if (!res.contains(node.val)) {
        res.add(node.val);
      }
      helper(node.left);

      helper(node.right);
    }

    helper(root);

    if (res.length < 2) {
      return -1;
    }

    res.sort();

    return res[1];
  }
}
