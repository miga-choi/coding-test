function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursion - DFS
 *
 * Complexities:
 *   M - The number of nodes in `p`
 *   N - The number of nodes in `q`
 *   H𝗉 - The heights of `p`
 *   H𝗊 - The heights of `q`
 *   - Time Complexity: O(min(M, N))
 *   - Space Complexity: O(min(H𝗉, H𝗊))
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function (p, q) {
  if (p === null && q === null) {
    return true;
  }

  if (p === null || q === null || p.val !== q.val) {
    return false;
  }

  return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
};


// Solution
/**
 * Solution 1
 *
 * Recursion - DFS
 *
 * Complexities:
 *   M - The number of nodes in `p`
 *   N - The number of nodes in `q`
 *   H𝗉 - The heights of `p`
 *   H𝗊 - The heights of `q`
 *   - Time Complexity: O(min(M, N))
 *   - Space Complexity: O(min(H𝗉, H𝗊))
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
function solution1(p, q) {
  if (!p && !q) {
    return true;
  }

  if (!p || !q || p.val !== q.val) {
    return false;
  }

  return solution1(p.left, q.left) && solution1(p.right, q.right);
}

/**
 * Solution 2
 *
 * Iteration - BFS
 *
 * Complexities:
 *   M - The number of nodes in `p`
 *   N - The number of nodes in `q`
 *   H𝗉 - The heights of `p`
 *   H𝗊 - The heights of `q`
 *   - Time Complexity: O(min(M, N))
 *   - Space Complexity: O(min(H𝗉, H𝗊))
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
function solution2(p, q) {
  const queue = [[p, q]];

  while (queue.length > 0) {
    const [node1, node2] = queue.shift();

    if (!node1 && !node2) {
      continue;
    }

    if (!node1 || !node2 || node1.val !== node2.val) {
      return false;
    }

    queue.push([node1.left, node2.left]);
    queue.push([node1.right, node2.right]);
  }

  return true;
}
