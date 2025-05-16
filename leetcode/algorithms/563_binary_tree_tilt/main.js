function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var findTilt = function (root) {
  let result = 0;

  /**
   * @param {TreeNode} node
   * @return {number}
   */
  function getVal(node) {
    if (node) {
      const left = getVal(node.left);
      const right = getVal(node.right);
      result += Math.abs(left - right);
      return left + right + node.val;
    } else {
      return 0;
    }
  }

  getVal(root);

  return result;
};


// Solution
// Solution 1: DFS
var solution1 = function (root) {
  const tilt = { val: 0 };
  dfs(root, tilt);
  return tilt.val;
};

function dfs(root, tilt) {
  if (!root) {
    return 0;
  }

  let left = dfs(root.left, tilt);
  let right = dfs(root.right, tilt);

  tilt.val += Math.abs(left - right);

  return root.val + left + right;
}

// Solution 2
var solution2 = function (root) {
  let tot = 0;

  findSum(root);

  return tot;

  function findSum(node) {
    // base case
    if (node == null) {
      return 0;
    }

    const left = findSum(node.left);
    const right = findSum(node.right);

    const sum = left + right;

    tot += Math.abs(left - right);

    return sum + node.val;
  }
};
