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
var solution1 = function (root) {
  const result = [];

  function traverse(node) {
    if (!node) {
      return;
    }

    result.push(node.val);
    traverse(node.left);
    traverse(node.right);
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
var solution2 = function (root) {
  if (!root) {
    return [];
  }

  const result = [];
  const stack = [root];

  while (stack.length > 0) {
    const node = stack.pop();
    result.push(node.val);

    if (node.right !== null) {
      stack.push(node.right);
    }

    if (node.left !== null) {
      stack.push(node.left);
    }
  }

  return result;
};
