function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursion - DFS
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} targetSum_
 * @param {number} sum_
 * @param {TreeNode} node_
 * @return {boolean}
 */
const checkSum = (targetSum, sum, depth, node) => {
  if (!node) {
    return false;
  }

  if (node.val === targetSum && !node.left && !node.right && depth === 1) {
    return true;
  }

  const sum = sum + node.val;
  if (sum === targetSum && depth > 1 && !node.left && !node.right) {
    return true;
  } else {
    return (
      checkSum(targetSum, sum, depth + 1, node.left) ||
      checkSum(targetSum, sum, depth + 1, node.right)
    );
  }
};

/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function (root, targetSum) {
  return checkSum(targetSum, 0, 1, root);
};


// Solution
/**
 * Solution 1
 *
 * Recursion - DFS
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
var solution1 = function (root, targetSum) {
  if (root === null) {
    return false;
  }

  if (root.left === null && root.right === null) {
    return targetSum === root.val;
  }

  const remainingSum = targetSum - root.val;

  return (
    solution1(root.left, remainingSum) || solution1(root.right, remainingSum)
  );
};

/**
 * Solution 2
 *
 * Iteration - DFS with Stack
 *
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
var solution2 = function (root, targetSum) {
  if (root === null) {
    return false;
  }

  const stack = [[root, targetSum - root.val]];

  while (stack.length > 0) {
    const [node, currentTarget] = stack.pop();

    if (node.left === null && node.right === null && currentTarget === 0) {
      return true;
    }

    if (node.right !== null) {
      stack.push([node.right, currentTarget - node.right.val]);
    }
    if (node.left !== null) {
      stack.push([node.left, currentTarget - node.left.val]);
    }
  }

  return false;
};
