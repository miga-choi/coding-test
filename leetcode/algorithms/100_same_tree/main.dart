class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SameTree {
  bool isSameTree(TreeNode? p, TreeNode? q) {
    if (p == null && q == null) {
      return true;
    }

    if (p != null && q != null) {
      return isSameTree(p.left, q.left) &&
          isSameTree(p.right, q.right) &&
          p.val == q.val;
    }

    return false;
  }


  // Solution
  bool solution(TreeNode? p, TreeNode? q) {
    if (p == null && q == null) {
      return true;
    }
    if (p == null || q == null) {
      return false;
    }

    final result =
        p.val == q.val &&
        isSameTree(p.left, q.left) &&
        isSameTree(p.right, q.right);

    return result;
  }
}
