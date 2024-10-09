class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class PathSum {
  bool hasPathSum(TreeNode? root, int targetSum) {
    if (root == null) {
      return false;
    }

    if (root.left == null && root.right == null) {
      return (targetSum - root.val) == 0;
    }

    return hasPathSum(root.left, targetSum - root.val) ||
        hasPathSum(root.right, targetSum - root.val);
  }

  // Best Solution
  bool bestSolution(TreeNode? root, int targetSum) {
    if (root == null) return false;

    if (root.left == null && root.right == null && root.val == targetSum)
      return true;

    return hasPathSum(root.left, targetSum - root.val) ||
        hasPathSum(root.right, targetSum - root.val);
  }
}
