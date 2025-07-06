function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} node
 * @param {number[]} vals
 */
var inorderTraversal = function (node, vals) {
  if (!node) {
    return;
  }

  inorderTraversal(node.left, vals);
  vals.push(node.val);
  inorderTraversal(node.right, vals);
};

/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDiffInBST = function (root) {
  const vals = Array();

  inorderTraversal(root, vals);

  let min = 10e5;

  for (let i = 0; i < vals.length - 1; i++) {
    const diff = vals[i + 1] - vals[i];
    if (diff < min) {
      min = diff;
    }
  }

  return min;
};
