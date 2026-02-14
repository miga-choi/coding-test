function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursion: DFS
 *
 * Complexities:
 *   N - Size of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {TreeNode} node
 * @param {number} minVal
 * @param {number} maxVal
 * @return {boolean}
 */
var helper = function (node, minVal, maxVal) {
  if (node === null) {
    return true;
  }

  if (node.val <= minVal || node.val >= maxVal) {
    return false;
  }

  return (
    helper(node.left, minVal, node.val) && helper(node.right, node.val, maxVal)
  );
};

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function (root) {
  return helper(root, -Infinity, Infinity);
};


// Solution
/**
 * Solution 1
 *
 * Recursive with Range
 *
 * Complexities:
 *   N - Size of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var solution1 = function (root) {
  const validate = (node, min, max) => {
    if (!node) {
      return true;
    }

    if (node.val <= min || node.val >= max) {
      return false;
    }

    return (
      validate(node.left, min, node.val) && validate(node.right, node.val, max)
    );
  };

  return validate(root, -Infinity, Infinity);
};

/**
 * Solution 2
 *
 * Inorder Traversal
 *
 * Complexities:
 *   N - Size of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var solution2 = function (root) {
  let prev = -Infinity;

  const inorder = (node) => {
    if (!node) {
      return true;
    }

    if (!inorder(node.left)) {
      return false;
    }

    if (node.val <= prev) {
      return false;
    }
    prev = node.val;

    return inorder(node.right);
  };

  return inorder(root);
};
