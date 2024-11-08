class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class CountCompleteTreeNodes {
  int countNodes(TreeNode? root) {
    int count = 0;
    if (root != null) {
      count++;
      if (root.left != null) {
        count += countNodes(root.left);
      }
      if (root.right != null) {
        count += countNodes(root.right);
      }
    }
    return count;
  }
}
