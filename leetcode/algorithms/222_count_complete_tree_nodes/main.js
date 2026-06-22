function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * DFS
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(logᴺ)
 */
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


// Solution
/**
 * Solution 1
 *
 * DFS
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var solution1 = function (root) {
  if (!root) {
    return 0;
  }

  return 1 + solution1(root.left) + solution1(root.right);
};

/**
 * Solution 2
 *
 * Perfect Binary Tree
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   - Time Complexity: O(log₂ᴺ)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var solution2 = function (root) {
  if (!root) {
    return 0;
  }

  let leftDepth = 0;
  let curr = root;
  while (curr) {
    leftDepth++;
    curr = curr.left;
  }

  let rightDepth = 0;
  curr = root;
  while (curr) {
    rightDepth++;
    curr = curr.right;
  }

  if (leftDepth === rightDepth) {
    return Math.pow(2, leftDepth) - 1;
  }

  return 1 + solution2(root.left) + solution2(root.right);
};
