class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreeInorderTraversal {
  List<int> inorderTraversal(TreeNode? root) {
    if (root == null) {
      return List<int>.empty();
    }

    List<int> result = List<int>.empty(growable: true);

    int addVal(TreeNode node) {
      if (node.left != null) {
        addVal(node.left!);
      }

      result.add(node.val);

      if (node.right != null) {
        addVal(node.right!);
      }

      return node.val;
    }

    addVal(root);

    return result;
  }

  // Best Solution
  List<int> bestSolution(TreeNode? root) {
    List<int> list = [];
    inOrderHelper(root, list);
    return list;
  }

  inOrderHelper(TreeNode? root, List<int> list) {
    if (root != null) {
      inOrderHelper(root.left, list);
      list.add(root.val);
      inOrderHelper(root.right, list);
    }
  }
}
