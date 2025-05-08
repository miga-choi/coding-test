class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SearchInABinarySearchTree {
  TreeNode? searchBST(TreeNode? root, int val) {
    if (root != null) {
      if (root.val == val) {
        return root;
      }

      TreeNode? left = searchBST(root.left, val);
      if (left != null) {
        return left;
      }

      TreeNode? right = searchBST(root.right, val);
      if (right != null) {
        return right;
      }
    }

    return null;
  }


  // Solution
  // Solution 1: Recursion
  TreeNode? solution1(TreeNode? root, int val) {
    if (root == null) {
      return root;
    }

    if (root.val == val) {
      return root;
    }

    return root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
  }

  // Solution 2: Iteration
  TreeNode? solution2(TreeNode? root, int val) {
    while (root != null && root.val != val) {
      root = root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
    }
    return root;
  }
}
