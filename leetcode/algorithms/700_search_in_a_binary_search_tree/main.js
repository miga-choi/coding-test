function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function (root, val) {
  if (root) {
    if (root.val == val) {
      return root;
    }

    const left = searchBST(root.left, val);
    if (left) {
      return left;
    }

    const right = searchBST(root.right, val);
    if (right) {
      return right;
    }
  }

  return null;
};


// Solution
// Solution 1: Recursion
var solution1 = function (root, val) {
  if (root == null) {
    return root;
  }

  if (root.val == val) {
    return root;
  }

  return root.val > val ? solution1(root.left, val) : solution1(root.right, val);
};

// Solution 2: Iteration
var solution2 = function (root, val) {
  while (root != null && root.val != val) {
    root = root.val > val ? solution2(root.left, val) : solution2(root.right, val);
  }
  return root;
};
