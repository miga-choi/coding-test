class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class CountCompleteTreeNodes {
  /**
   * DFS
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(logᴺ)
   */
  int countNodes(TreeNode? root) {
    int count = 0;

    if (root != null) {
      count++;
      if (root.left != null) {
        count += countNodes(root.left);
      }
      if (root.right != null) {
        count += countNodes(root.right);
      }
    }

    return count;
  }


  // Solution
  /**
   * Perfect Binary Tree
   *
   * Complexities:
   *   N - Number of nodes in `root`
   *   - Time Complexity: O(log₂ᴺ)
   *   - Space Complexity: O(logᴺ)
   */
  int solution(TreeNode? root) {
    if (root == null) return 0;

    int leftHeight = _getHeight(root.left);
    int rightHeight = _getHeight(root.right);

    if (leftHeight == rightHeight) {
      return (1 << leftHeight) + solution(root.right);
    } else {
      return (1 << rightHeight) + solution(root.left);
    }
  }

  int _getHeight(TreeNode? node) {
    int height = 0;
    while (node != null) {
      height++;
      node = node.left;
    }
    return height;
  }
}
