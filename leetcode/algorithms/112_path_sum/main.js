function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {number} targetSum_
 * @param {number} sum_
 * @param {TreeNode} node_
 * @return {boolean}
 */
const checkSum = (targetSum, sum, depth, node) => {
  if (!node) {
    return false;
  }

  if (node.val === targetSum && !node.left && !node.right && depth === 1) {
    return true;
  }

  const sum = sum + node.val;
  if (sum === targetSum && depth > 1 && !node.left && !node.right) {
    return true;
  } else {
    return (
      checkSum(targetSum, sum, depth + 1, node.left) ||
      checkSum(targetSum, sum, depth + 1, node.right)
    );
  }
};

/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function (root, targetSum) {
  return checkSum(targetSum, 0, 1, root);
};


// Solution
// Solution 1: Recursion
var solution1 = function (root, targetSum) {
  if (!root) {
    return false;
  }

  if (!root.left && !root.right) {
    // check leaf
    return targetSum === root.val;
  } else {
    // continue DFS
    return (
      solution1(root.left, targetSum - root.val) ||
      solution1(root.right, targetSum - root.val)
    );
  }
};

// Solution 2:
var solution2 = function (root, targetSum) {
  // If the tree is empty i.e. root is NULL, return false...
  if (root == null) {
    return false;
  }

  // If there is only a single root node and the value of root node is equal to the targetSum...
  if (root.val == targetSum && root.left == null && root.right == null) {
    return true;
  }

  // Call the same function recursively for left and right subtree...
  return (
    solution2(root.left, targetSum - root.val) ||
    solution2(root.right, targetSum - root.val)
  );
};
