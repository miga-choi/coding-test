function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursion (DFS)
 *
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   H - The Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumOfLeftLeaves = function (root) {
  if (!root) {
    return 0;
  }

  let result = 0;

  if (root.left) {
    if (!root.left.left && !root.left.right) {
      result += root.left.val;
    } else {
      result += sumOfLeftLeaves(root.left);
    }
  }

  result += sumOfLeftLeaves(root.right);

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Recursion (DFS)
 *
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   H - The Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var solution1 = function (root) {
  if (!root) {
    return 0;
  }

  let sum = 0;
  const left = root.left;

  if (left && !left.left && !left.right) {
    sum += left.val;
  } else {
    sum += solution1(left);
  }

  sum += solution1(root.right);

  return sum;
};

/**
 * Solution 2
 *
 * Recursion (DFS) with Flag
 *
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   H - The Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var solution2 = function (root) {
  const dfs = (node, isLeft) => {
    if (!node) {
      return 0;
    }

    if (!node.left && !node.right) {
      return isLeft ? node.val : 0;
    }

    return dfs(node.left, true) + dfs(node.right, false);
  };

  return dfs(root, false);
};

/**
 * Solution 3
 *
 * Iteration (BFS) with Queue
 *
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   W - The Width of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(W)
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var solution3 = function (root) {
  if (!root) {
    return 0;
  }

  let sum = 0;
  const queue = [root];
  let head = 0;

  while (head < queue.length) {
    const node = queue[head++];

    if (node.left) {
      if (!node.left.left && !node.left.right) {
        sum += node.left.val;
      } else {
        queue.push(node.left);
      }
    }

    if (node.right) {
      queue.push(node.right);
    }
  }

  return sum;
};
