class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class FindModeInBinarySearchTree {
  int countNum(TreeNode? root, Map<int, int> numCountMap, int maxCount) {
    if (root != null) {
      maxCount = countNum(root.left, numCountMap, maxCount);
      numCountMap[root.val] = numCountMap[root.val] == null ? 1 : numCountMap[root.val]! + 1;
      if (numCountMap[root.val]! > maxCount) {
        maxCount = numCountMap[root.val]!;
      }
      maxCount = countNum(root.right, numCountMap, maxCount);
    }
    return maxCount;
  }

  List<int> findMode(TreeNode? root) {
    final Map<int, int> numCountMap = Map<int, int>();
    int maxCount = 0;
    maxCount = countNum(root, numCountMap, maxCount);

    print(maxCount);

    final List<int> result = List<int>.empty(growable: true);

    for (int key in numCountMap.keys) {
      if (numCountMap[key] == maxCount) {
        result.add(key);
      }
    }

    return result;
  }

  // Solution
  List<int> ans = [];
  TreeNode? prev;
  int c = 1, max = 0;

  void sol(TreeNode? root) {
    if (root == null) {
      return;
    }
    sol(root.left);
    if (prev != null) {
      if (root.val == prev!.val) {
        c++;
      } else {
        c = 1;
      }
    }
    prev = TreeNode(root.val);
    if (c > max) {
      max = c;
      ans.clear();
      ans.add(root.val);
    } else if (c == max) {
      ans.add(root.val);
    }
    sol(root.right);
  }

  List<int> solution(TreeNode? root) {
    ans = [];
    sol(root);
    return ans;
  }
}
