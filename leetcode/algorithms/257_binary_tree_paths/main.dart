class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreePaths {
  void calculatePath(TreeNode? root, List<String> stringArray, String string) {
    if (root != null) {
      string = "$string${string.isEmpty ? "" : "->"}${root.val}";
      if (root.left == null && root.right == null) {
        stringArray.add(string);
      } else {
        calculatePath(root.left, stringArray, string);
        calculatePath(root.right, stringArray, string);
      }
    }
  }

  List<String> binaryTreePaths(TreeNode? root) {
    List<String> stringArray = List<String>.empty(growable: true);
    calculatePath(root, stringArray, "");
    return stringArray;
  }

  // Best Solution
  List<String> ans = [];
  String arrow = '->';

  List<String> bestSolution(TreeNode? root) {
    if (root == null) return [];
    void helper(TreeNode? root, String s) {
      if (root == null) return;
      s += '${root.val}';
      if (root.left != null) helper(root.left, s + arrow);
      if (root.right != null) helper(root.right, s + arrow);
      if (root.left == null && root.right == null) ans.add(s);
    }

    helper(root, '');
    return ans;
  }
}
