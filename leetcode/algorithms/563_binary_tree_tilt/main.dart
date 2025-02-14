class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreeTilt {
  int findTilt(TreeNode? root) {
    int total = 0;

    int sumVal(TreeNode? node) {
      if (node == null) {
        return 0;
      }

      int left = sumVal(node.left);
      int right = sumVal(node.right);

      total += (left - right).abs();

      return left + right + node.val;
    }

    sumVal(root);

    return total;
  }

  // Solution
  int totalTilt = 0;

  int valueSum(TreeNode? node) {
    if (node == null) {
      return 0;
    }

    int leftSum = valueSum(node.left);
    int rightSum = valueSum(node.right);
    int tilt = (leftSum - rightSum).abs();
    totalTilt += tilt;

    // return the sum of values starting from this node.
    return node.val + leftSum + rightSum;
  }

  int solution(TreeNode? root) {
    totalTilt = 0;
    valueSum(root);
    return totalTilt;
  }
}
