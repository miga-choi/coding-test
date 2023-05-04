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
 * @return {number}
 */
var maxDepth = function (root) {
  if (!root) {
    return 0;
  }
  return returnDepth(0, root);
};

/**
 * @param {number} depth_
 * @param {TreeNode} node_
 * @return {number}
 */
var returnDepth = function (depth_, node_) {
  let depth = depth_ + 1;
  if (node_.left) {
    const leftDepth = returnDepth(depth_ + 1, node_.left);
    if (leftDepth > depth) {
      depth = leftDepth;
    }
  }
  if (node_.right) {
    const rightDepth = returnDepth(depth_ + 1, node_.right);
    if (rightDepth > depth) {
      depth = rightDepth;
    }
  }
  return depth;
};

// Best Solution
var bestSolution = function (root) {
  if (root === undefined || root === null) {
    return 0;
  }
  return Math.max(bestSolution(root.left), bestSolution(root.right)) + 1;
};
