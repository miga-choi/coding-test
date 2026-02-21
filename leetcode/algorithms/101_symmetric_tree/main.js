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
 * @param {TreeNode} leftNode
 * @param {TreeNode} rightNode
 */
function checkNode(leftNode, rightNode) {
  if (!leftNode && !rightNode) {
    return true;
  } else if ((leftNode && !rightNode) || (!leftNode && rightNode)) {
    return false;
  } else if (leftNode.val !== rightNode.val) {
    return false;
  } else {
    return (
      checkNode(leftNode.left, rightNode.right) &&
      checkNode(leftNode.right, rightNode.left)
    );
  }
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function (root) {
  if (!root) {
    return true;
  }
  return checkNode(root.left, root.right);
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
 * @return {boolean}
 */
var solution1 = function (root) {
  if (!root) {
    return true;
  }

  function isMirror(t1, t2) {
    if (!t1 && !t2) {
      return true;
    }

    if (!t1 || !t2 || t1.val !== t2.val) {
      return false;
    }

    return isMirror(t1.left, t2.right) && isMirror(t1.right, t2.left);
  }

  return isMirror(root.left, root.right);
};

/**
 * Solution 2
 *
 * Iteration
 *
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The heights of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var solution2 = function (root) {
  if (!root) {
    return true;
  }

  const stack = [root.left, root.right];

  while (stack.length > 0) {
    const t1 = stack.pop();
    const t2 = stack.pop();

    if (!t1 && !t2) {
      continue;
    }

    if (!t1 || !t2 || t1.val !== t2.val) {
      return false;
    }

    stack.push(t1.left, t2.right);
    stack.push(t1.right, t2.left);
  }

  return true;
};
