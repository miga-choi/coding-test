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
 * @return {number[]}
 */
var preorderTraversal = function (root) {
  const result = [];
  const totalNodes = [];

  if (root) {
    totalNodes.push(root);

    while (totalNodes.length > 0) {
      const node = totalNodes.pop();
      result.push(node.val);

      if (node.right) {
        totalNodes.push(node.right);
      }

      if (node.left) {
        totalNodes.push(node.left);
      }
    }
  }

  return result;
};

// Best Solution
var bestSolution = function (root) {
  if (!root) return [];
  var result = [];
  var stack = [root];

  while (stack.length) {
    var node = stack.pop();
    result.push(node.val);
    if (node.right) stack.push(node.right);
    if (node.left) stack.push(node.left);
  }
  return result;
};
