class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class InvertBinaryTree {
  TreeNode? invertTree(TreeNode? root) {
    if (root != null) {
      TreeNode? tempNode = root.left;
      root.left = invertTree(root.right);
      root.right = invertTree(tempNode);
    }
    return root;
  }

  // Best Solution
  TreeNode? bestSolution(TreeNode? root) {
    return root == null ? root : TreeNode(root.val, invertTree(root.right), invertTree(root.left));
  }
}
