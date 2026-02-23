function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursion - DFS
 *
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The heights of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
  if (root === null) {
    return 0;
  }

  const left = maxDepth(root.left);
  const right = maxDepth(root.right);

  return (left > right ? left : right) + 1;
};

// Solution
/**
 * Solution 1
 *
 * Recursion - DFS
 *
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The heights of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var solution1 = function (root) {
  if (root === null) {
    return 0;
  }

  const leftDepth = solution1(root.left);
  const rightDepth = solution1(root.right);

  return 1 + Math.max(leftDepth, rightDepth);
};

/**
 * Solution 2
 *
 * Iteration - BFS
 *
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The heights of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var solution2 = function (root) {
  if (root === null) {
    return 0;
  }

  const queue = [root];
  let depth = 0;

  while (queue.length > 0) {
    const levelSize = queue.length;

    for (let i = 0; i < levelSize; i++) {
      const node = queue.shift();

      if (node.left !== null) {
        queue.push(node.left);
      }
      if (node.right !== null) {
        queue.push(node.right);
      }
    }

    depth++;
  }

  return depth;
};

/**
 * Solution 3
 *
 * Iteration: DFS (Stack)
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 *
 * @param {TreeNode} root
 * @return {number}
 */
var solution3 = function (root) {
  if (root === null) {
    return 0;
  }

  const stack = [[root, 1]];
  let maxDepth = 0;

  while (stack.length > 0) {
    const [node, depth] = stack.pop();

    maxDepth = Math.max(maxDepth, depth);

    if (node.left) {
      stack.push([node.left, depth + 1]);
    }
    if (node.right) {
      stack.push([node.right, depth + 1]);
    }
  }

  return maxDepth;
};
