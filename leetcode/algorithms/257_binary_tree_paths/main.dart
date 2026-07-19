class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreePaths {
  /**
   * DFS + Backtracking
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The height of tree in `root`
   *   - Time Complexity: O(N * H)
   *   - Space Complexity: O(H)
   */
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


  // Solution
  /**
   * DFS + Backtracking
   *
   * Complexities:
   *   N - The number of nodes in `root`
   *   H - The height of tree in `root`
   *   - Time Complexity: O(N * H)
   *   - Space Complexity: O(H)
   */
  List<String> solution(TreeNode? root) {
    List<String> result = [];
    if (root == null) {
      return result;
    }

    List<int> currentPath = [];
    _backtrack(root, currentPath, result);

    return result;
  }

  void _backtrack(TreeNode node, List<int> currentPath, List<String> result) {
    currentPath.add(node.val);

    if (node.left == null && node.right == null) {
      result.add(currentPath.join("->"));
    } else {
      if (node.left != null) {
        _backtrack(node.left!, currentPath, result);
      }
      if (node.right != null) {
        _backtrack(node.right!, currentPath, result);
      }
    }

    currentPath.removeLast();
  }
}
