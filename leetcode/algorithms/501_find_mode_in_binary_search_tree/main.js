/**
 * Definition for a binary tree node.
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
var findMode = function (root) {
  const map = new Map();

  /**
   * @param {TreeNode} node
   * @returns
   */
  const checkVal = (node) => {
    if (!node) {
      return;
    }
    if (node.left) {
      checkVal(node.left);
    }
    if (node.right) {
      checkVal(node.right);
    }
    if (!map.get(node.val)) {
      map.set(node.val, 1);
    } else {
      map.set(node.val, map.get(node.val) + 1);
    }
  };

  checkVal(root);

  return [...map.entries()]
    .filter((v) => v[1] === Math.max(...map.values()))
    .map(([k]) => k);
};


// Best Solution
var bestSolution = function (root) {
  const counts = {};
  let maxCount = 0;
  const modes = [];

  const inorder = function (node) {
    if (!node) {
      return;
    }

    inorder(node.left);

    const count = (counts[node.val] || 0) + 1;
    counts[node.val] = count;

    if (count > maxCount) {
      maxCount = count;
      modes.length = 0;
      modes.push(node.val);
    } else if (count === maxCount) {
      modes.push(node.val);
    }

    inorder(node.right);
  };

  inorder(root);

  return modes;
};
