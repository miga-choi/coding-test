function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function (root) {
  let result = 0;

  getMaxNode(root);

  function getMaxNode(root) {
    if (!root) {
      return 0;
    }

    const left = getMaxNode(root.left);
    const right = getMaxNode(root.right);

    result = Math.max(result, left + right);

    return Math.max(left, right) + 1;
  }

  return result;
};


// Solution
var solution = function (root) {
  let diameter = 0;

  dfs(root);

  return diameter;

  function dfs(node) {
    if (!node) {
      return 0;
    }

    const left = dfs(node.left);
    const right = dfs(node.right);

    // update diameter at every node
    diameter = Math.max(diameter, left + right);

    // update the largest number of edge so far
    return 1 + Math.max(left, right);
  }
};
