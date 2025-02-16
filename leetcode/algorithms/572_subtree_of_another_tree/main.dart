class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SubtreeOfAnotherTree {
  bool compareNode(TreeNode? node1, TreeNode? node2) {
    if (node1 == null || node2 == null) {
      return node1 == null && node2 == null;
    }
    return node1.val == node2.val &&
        compareNode(node1.left, node2.left) &&
        compareNode(node1.right, node2.right);
  }

  bool isSubtree(TreeNode? root, TreeNode? subRoot) {
    if (root == null) {
      return subRoot == null;
    }
    return compareNode(root, subRoot) ||
        isSubtree(root.left, subRoot) ||
        isSubtree(root.right, subRoot);
  }

  // Solution
  bool solution(TreeNode? root, TreeNode? subRoot) {
    if (root == null) {
      return false;
    }

    final isSubtreeIsEqual = isTreeEqual(root, subRoot);
    if (isSubtreeIsEqual) {
      return true;
    } else {
      final leftResult = solution(root.left, subRoot);
      final rightResult = solution(root.right, subRoot);
      return leftResult | rightResult;
    }
  }

  bool isTreeEqual(TreeNode? root, TreeNode? anotherRoot) {
    if (root == null || anotherRoot == null) {
      return root == anotherRoot;
    }
    final currNodeEquality = (root.val == anotherRoot.val);
    return currNodeEquality &
        isTreeEqual(root.left, anotherRoot.left) &
        isTreeEqual(root.right, anotherRoot.right);
  }
}
