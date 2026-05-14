function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Iteration
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function (root) {
  const result = [];
  const nodes = [];

  if (root) {
    nodes.push(root);

    while (nodes.length > 0) {
      const node = nodes.pop();

      result.push(node.val);

      if (node.left) {
        nodes.push(node.left);
      }

      if (node.right) {
        nodes.push(node.right);
      }
    }
  }

  return result.reverse();
};


// Solution
/**
 * Solution 1
 *
 * Recursion
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var solution1 = function (root) {
  const result = [];

  function traverse(node) {
    if (!node) {
      return;
    }

    traverse(node.left);
    traverse(node.right);
    result.push(node.val);
  }

  traverse(root);

  return result;
};

/**
 * Solution 2
 *
 * Iteration
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var solution2 = function (root) {
  if (!root) {
    return [];
  }

  const result = [];
  const stack = [root];

  while (stack.length > 0) {
    const node = stack.pop();
    result.push(node.val);

    if (node.left !== null) {
      stack.push(node.left);
    }
    if (node.right !== null) {
      stack.push(node.right);
    }
  }

  return result.reverse();
};
