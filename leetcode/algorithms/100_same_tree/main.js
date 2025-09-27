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
 * Recursion: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 *
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
function solution1(p, q) {
  if (p === null && q === null) {
    return true;
  }

  if (p === null || q === null || p.val !== q.val) {
    return false;
  }

  return solution1(p.left, q.left) && solution1(p.right, q.right);
}

/**
 * Solution 2
 *
 * Iteration: DFS (Stack)
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 *
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
function solution2(p, q) {
  const stack = [[p, q]];

  while (stack.length > 0) {
    const [nodeP, nodeQ] = stack.pop();

    if (nodeP === null && nodeQ === null) {
      continue;
    }

    if (nodeP === null || nodeQ === null || nodeP.val !== nodeQ.val) {
      return false;
    }

    stack.push([nodeP.right, nodeQ.right]);
    stack.push([nodeP.left, nodeQ.left]);
  }

  return true;
}

/**
 * Solution 3
 *
 * Iteration: BFS (Queue)
 * - Time Complexity: O(N)
 * - Space Complexity: O(W)
 *
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
function solution3(p, q) {
  const queue = [[p, q]];

  while (queue.length > 0) {
    const [nodeP, nodeQ] = queue.shift();

    if (nodeP === null && nodeQ === null) {
      continue;
    }

    if (nodeP === null || nodeQ === null || nodeP.val !== nodeQ.val) {
      return false;
    }

    queue.push([nodeP.left, nodeQ.left]);
    queue.push([nodeP.right, nodeQ.right]);
  }

  return true;
}
