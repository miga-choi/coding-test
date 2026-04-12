function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursion: DFS
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Width of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 *
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function (root) {
  if (root === null) {
    return 0;
  }

  const leftDepth = minDepth(root.left);
  const rightDepth = minDepth(root.right);

  if (leftDepth === 0 || rightDepth === 0) {
    return Math.max(leftDepth, rightDepth) + 1;
  }

  return Math.min(leftDepth, rightDepth) + 1;
};


// Solution
/**
 * Solution 1
 *
 * Iteration: BFS (Queue)
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   W - Width of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(W)
 *
 * @param {TreeNode} root
 * @return {number}
 */
var solution1 = function (root) {
  if (!root) {
    return 0;
  }

  const queue = [root];
  let depth = 1;

  while (queue.length > 0) {
    const levelSize = queue.length;

    for (let i = 0; i < levelSize; i++) {
      const node = queue.shift();

      if (node.left === null && node.right === null) {
        return depth;
      }

      if (node.left) {
        queue.push(node.left);
      }
      if (node.right) {
        queue.push(node.right);
      }
    }

    depth++;
  }

  return depth;
};

/**
 * Solution 2
 *
 * Recursion: DFS
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 *
 * @param {TreeNode} root
 * @return {number}
 */
var solution2 = function (root) {
  if (!root) {
    return 0;
  }

  if (root.left === null) {
    return solution2(root.right) + 1;
  }

  if (root.right === null) {
    return solution2(root.left) + 1;
  }

  return Math.min(solution2(root.left), solution2(root.right)) + 1;
};
