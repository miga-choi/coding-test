function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * DFS + Backtracking
 *
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The height of tree in `root`
 *   - Time Complexity: O(N * H)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function (root) {
  if (!root) {
    return [];
  }

  if (!root.left && !root.right) {
    return [`${root.val}`];
  }

  const leftArray = binaryTreePaths(root.left);
  const rightArray = binaryTreePaths(root.right);

  const left = leftArray.map((v_) => `${root.val}->${v_}`);
  const right = rightArray.map((v_) => `${root.val}->${v_}`);

  return [...left, ...right];
};


// Solution
/**
 * DFS + Backtracking
 *
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The height of tree in `root`
 *   - Time Complexity: O(N * H)
 *   - Space Complexity: O(H)
 */
var solution = function (root) {
  const result = [];

  function dfs(node, currentPath) {
    if (!node) {
      return;
    }

    const nextPath = currentPath
      ? `${currentPath}->${node.val}`
      : `${node.val}`;

    if (!node.left && !node.right) {
      result.push(nextPath);
      return;
    }

    dfs(node.left, nextPath);
    dfs(node.right, nextPath);
  }

  dfs(root, "");

  return result;
};
