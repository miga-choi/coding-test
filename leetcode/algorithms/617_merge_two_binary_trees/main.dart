class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class MergeTwoBinaryTrees {
  TreeNode? mergeTrees(TreeNode? root1, TreeNode? root2) {
    if (root1 == null) {
      return root2;
    }
    if (root2 == null) {
      return root1;
    }
    return TreeNode(
      root1.val + root2.val,
      mergeTrees(root1.left, root2.left),
      mergeTrees(root1.right, root2.right),
    );
  }

  // Solution
  TreeNode? solution(TreeNode? root1, TreeNode? root2) {
    if (root1 == null) {
      return root2;
    } else if (root2 == null) {
      return root1;
    }
    root1.val += root2.val;
    root1.left = (mergeTrees(root1.left, root2.left));
    root1.right = (mergeTrees(root1.right, root2.right));
    return root1;
  }
}
