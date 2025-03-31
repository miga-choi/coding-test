class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class TwoSum4InputIsABST {
  void inorder(TreeNode? node, List<int> valArray) {
    if (node != null) {
      inorder(node.left, valArray);
      valArray.add(node.val);
      inorder(node.right, valArray);
    }
  }

  bool findTarget(TreeNode? root, int k) {
    List<int> valArray = List<int>.empty(growable: true);

    inorder(root, valArray);

    int left = 0;
    int right = valArray.length - 1;

    while (left < right) {
      int sum = valArray[left] + valArray[right];
      if (sum < k) {
        left++;
      } else if (sum > k) {
        right--;
      } else {
        return true;
      }
    }

    return false;
  }

  // Solution: Using Set
  bool dfs(TreeNode? node, Set<int> valSet, int k) {
    if (node == null) {
      return false;
    }

    if (valSet.contains(k - node.val)) {
      return true;
    }

    valSet.add(node.val);

    return dfs(node.left, valSet, k) || dfs(node.right, valSet, k);
  }

  bool solution(TreeNode? root, int k) {
    Set<int> valSet = Set<int>();
    return dfs(root, valSet, k);
  }
}
