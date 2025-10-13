function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursion: DFS (Bottom-up)
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 *
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function (root) {
  let maxDiameter = 0;

  /**
   * @param {TreeNode} node
   * @returns {number}
   */
  function getMaxDiameter(node) {
    if (node === null) {
      return 0;
    }

    const leftDiameter = getMaxDiameter(node.left);
    const rightDiameter = getMaxDiameter(node.right);

    if (leftDiameter + rightDiameter > maxDiameter) {
      maxDiameter = leftDiameter + rightDiameter;
    }

    return Math.max(leftDiameter, rightDiameter) + 1;
  }

  getMaxDiameter(root);

  return maxDiameter;
};


// Solution
/**
 * Recursion: DFS (Bottom-up)
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
var solution = function (root) {
  let maxDiameter = 0;

  function dfs(node) {
    if (node === null) {
      return 0;
    }

    const leftHeight = dfs(node.left);
    const rightHeight = dfs(node.right);

    maxDiameter = Math.max(maxDiameter, leftHeight + rightHeight);

    return 1 + Math.max(leftHeight, rightHeight);
  }

  dfs(root);

  return maxDiameter;
};
