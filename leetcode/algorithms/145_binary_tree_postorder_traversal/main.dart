class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreePostorderTraversal {
  void addVal(TreeNode? node, List<int> result) {
    if (node != null) {
      addVal(node.left, result);
      addVal(node.right, result);
      result.add(node.val);
    }
  }

  List<int> postorderTraversal(TreeNode? root) {
    List<int> result = List<int>.empty(growable: true);
    addVal(root, result);
    return result;
  }


  // Solution
  List<int> solution(TreeNode? root) {
    if (root == null) {
      return [];
    }
    List<int> result = [];
    result.addAll(postorderTraversal(root.left));
    result.addAll(postorderTraversal(root.right));
    result.add(root.val);
    return result;
  }
}
