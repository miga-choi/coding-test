/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

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
    return checkSum(targetSum_, sum, depth_ + 1, node_.left) || checkSum(targetSum_, sum, depth_ + 1, node_.right);
  }
};

// Best Solution
var bestSolution1 = function (root, sum) {
  return root
    ? !root.left && !root.right
      ? sum === root.val
      : bestSolution1(root.left, sum - root.val) || bestSolution1(root.right, sum - root.val)
    : false;
};

var bestSolution2 = function (root, sum) {
  if (!root) return false;

  if (!root.left && !root.right) {
    // check leaf
    return sum === root.val;
  } else {
    // continue DFS
    return bestSolution2(root.left, sum - root.val) || bestSolution2(root.right, sum - root.val);
  }
};
