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
var countNodes = function (root) {
  if (!root) {
    return 0;
  }
  return countNodes(root.left) + countNodes(root.right) + 1;
};


// Best Solution
var bestSolution = function (root) {
  function leftDepth(node) {
    if (!node) return 0;
    return leftDepth(node.left) + 1;
  }

  function rightDepth(node) {
    if (!node) return 0;
    return rightDepth(node.right) + 1;
  }

  function traverse(node) {
    const leftLen = leftDepth(node);
    const rightLen = rightDepth(node);

    if (leftLen === rightLen) return Math.pow(2, leftLen) - 1;
    return traverse(node.left) + traverse(node.right) + 1;
  }
  return traverse(root);
};
