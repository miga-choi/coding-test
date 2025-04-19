class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SymmetricTree {
  bool isSymmetric(TreeNode? root) {
    if (root == null) {
      return true;
    }

    bool checkSymmetric(TreeNode? p, TreeNode? q) {
      if (p == null && q == null) {
        return true;
      }

      if (p != null && q != null) {
        return checkSymmetric(p.left, q.right) &&
            checkSymmetric(p.right, q.left) &&
            p.val == q.val;
      }

      return false;
    }

    return checkSymmetric(root.left, root.right);
  }

  // Solution
  bool solution(TreeNode? root) => isMirror(root, root);

  bool isMirror(TreeNode? t1, TreeNode? t2) {
    if (t1 == null && t2 == null) {
      return true;
    }
    if (t1 == null || t2 == null) {
      return false;
    }
    return t1.val == t2.val &&
        isMirror(t1.left, t2.right) &&
        isMirror(t1.right, t2.left);
  }
}
