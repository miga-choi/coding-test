function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursion: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
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
 * - Time Complexity: O(N)
 * - Space Complexity: O(W)
 *
 * @param {TreeNode} root
 * @return {number}
 */
var solution1 = function (root) {
  if (root === null) {
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
 * Solution 2
 *
 * Recursion: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 *
 * @param {TreeNode} root
 * @return {number}
 */
var solution2 = function (root) {
  if (root === null) {
    return 0;
  }

  const leftDepth = solution2(root.left);
  const rightDepth = solution2(root.right);

  if (root.left === null || root.right === null) {
    return 1 + leftDepth + rightDepth;
  }

  return 1 + Math.min(leftDepth, rightDepth);
};
