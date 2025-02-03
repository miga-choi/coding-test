class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class MinimumAbsoluteDifferenceInBST {
  int min = 100000;
  int val = 100000;

  int getMinimumDifference(TreeNode? root) {
    if (root != null) {
      getMinimumDifference(root.left);

      int diff = (root.val - val).abs();
      if (diff < min) {
        min = diff;
      }
      val = root.val;

      getMinimumDifference(root.right);
    }
    return min;
  }

  // Solution
  double prev = double.negativeInfinity;
  double ans = double.infinity;

  int solution(TreeNode? root) {
    inOrder(root);
    return ans.toInt();
  }

  void inOrder(TreeNode? root) {
    if (root == null) return;

    inOrder(root.left);

    if (prev != double.negativeInfinity) {
      ans = ans < (root.val - prev).abs() ? ans : (root.val - prev).abs();
    }
    prev = root.val.toDouble();

    inOrder(root.right);
  }
}
