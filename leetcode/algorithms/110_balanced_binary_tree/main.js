function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * DFS
 *
 * Complexities:
 *   N - Number of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} node
 * @return {number}
 */
const getMaxDepth = (node) => {
  if (node === null) {
    return 0;
  }

  const leftDepth = getMaxDepth(node.left);
  if (leftDepth < 0) {
    return -1;
  }

  const rightDepth = getMaxDepth(node.right);
  if (rightDepth < 0) {
    return -1;
  }

  if (Math.abs(leftDepth - rightDepth) > 1) {
    return -1;
  }

  return Math.max(leftDepth, rightDepth) + 1;
};

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function (root) {
  return getMaxDepth(root) !== -1;
};


// Solution
/**
 * DFS
 *
 * Complexities:
 *   N - Number of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var solution = function (root) {
  function checkHeight(node) {
    if (node === null) {
      return 0;
    }

    const leftHeight = checkHeight(node.left);
    if (leftHeight === -1) {
      return -1;
    }

    const rightHeight = checkHeight(node.right);
    if (rightHeight === -1) {
      return -1;
    }

    if (Math.abs(leftHeight - rightHeight) > 1) {
      return -1;
    }

    return Math.max(leftHeight, rightHeight) + 1;
  }

  return checkHeight(root) !== -1;
};
