function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function (root, targetSum) {
  return checkSum(targetSum, 0, 1, root);
};

/**
 * @param {number} targetSum_
 * @param {number} sum_
 * @param {TreeNode} node_
 * @return {boolean}
 */
const checkSum = (targetSum_, sum_, depth_, node_) => {
  if (!node_) {
    return false;
  }

  if (node_.val === targetSum_ && !node_.left && !node_.right && depth_ === 1) {
    return true;
  }

  const sum = sum_ + node_.val;
  if (sum === targetSum_ && depth_ > 1 && !node_.left && !node_.right) {
    return true;
  } else {
    return (
      checkSum(targetSum_, sum, depth_ + 1, node_.left) ||
      checkSum(targetSum_, sum, depth_ + 1, node_.right)
    );
  }
};


// Best Solution
// Best Solution 1: Recursion
var bestSolution1 = function (root, sum) {
  if (!root) {
    return false;
  }

  if (!root.left && !root.right) {
    // check leaf
    return sum === root.val;
  } else {
    // continue DFS
    return (
      hasPathSum(root.left, sum - root.val) ||
      hasPathSum(root.right, sum - root.val)
    );
  }
};

// Best Solution 2:
var bestSolution2 = function (root, sum) {
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
    hasPathSum(root.left, targetSum - root.val) ||
    hasPathSum(root.right, targetSum - root.val)
  );
};
