class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

/**
 * In-order Traversal to Array + Two-Pass Run Counting
 *
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(n)
 */
class FindModeInBinarySearchTree {
  int countNum(TreeNode? root, Map<int, int> numCountMap, int maxCount) {
    if (root != null) {
      maxCount = countNum(root.left, numCountMap, maxCount);
      numCountMap[root.val] = numCountMap[root.val] == null
          ? 1
          : numCountMap[root.val]! + 1;

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
  /**
   * Solution 1
   *
   * In-order Traversal + Run Counting
   *
   * Complexities:
   *   n - The Number of Nodes in `root`
   *   h - The Height of `root`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(h)
   */
  List<int> solution1(TreeNode? root) {
    final modes = <int>[];
    int? prev;
    var count = 0;
    var maxCount = 0;

    void visit(int v) {
      count = (v == prev) ? count + 1 : 1;
      prev = v;

      if (count > maxCount) {
        maxCount = count;
        modes
          ..clear()
          ..add(v);
      } else if (count == maxCount) {
        modes.add(v);
      }
    }

    void inorder(TreeNode? node) {
      if (node == null) {
        return;
      }

      inorder(node.left);
      visit(node.val);
      inorder(node.right);
    }

    inorder(root);

    return modes;
  }

  /**
   * Solution 2
   *
   * Morris Traversal
   *
   * Complexities:
   *   n - The Number of Nodes in `root`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  List<int> solution2(TreeNode? root) {
    final modes = <int>[];
    int? prev;
    var count = 0;
    var maxCount = 0;

    void visit(int v) {
      count = (v == prev) ? count + 1 : 1;
      prev = v;

      if (count > maxCount) {
        maxCount = count;
        modes
          ..clear()
          ..add(v);
      } else if (count == maxCount) {
        modes.add(v);
      }
    }

    var cur = root;

    while (cur != null) {
      final left = cur.left;

      if (left == null) {
        visit(cur.val);
        cur = cur.right;
        continue;
      }

      var pre = left;

      while (pre.right != null && pre.right != cur) {
        pre = pre.right!;
      }

      if (pre.right == null) {
        pre.right = cur;
        cur = left;
      } else {
        pre.right = null;
        visit(cur.val);
        cur = cur.right;
      }
    }

    return modes;
  }

  /**
   * Solution 3
   *
   * DFS + Hash Map
   *
   * Complexities:
   *   n - The Number of Nodes in `root`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(n)
   */
  List<int> solution3(TreeNode? root) {
    final freq = <int, int>{};

    void dfs(TreeNode? node) {
      if (node == null) {
        return;
      }

      freq.update(node.val, (c) => c + 1, ifAbsent: () => 1);
      dfs(node.left);
      dfs(node.right);
    }

    dfs(root);

    final maxCount = freq.values.reduce((a, b) => a > b ? a : b);

    return [ for (final e in freq.entries) if (e.value == maxCount) e.key ];
  }
}
