function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
  const totalRoots = new Array();
  const result = new Array();

  while (root || totalRoots.length > 0) {
    if (root) {
      totalRoots.push(root);
      root = root.left;
    } else {
      root = totalRoots.pop();
      result.push(root.val);
      root = root.right;
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Recursion
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {TreeNode} root
 * @return {number[]}
 */
function solution1(root) {
  const result = [];

  function traverse(node) {
    if (node === null) {
      return;
    }

    traverse(node.left);
    result.push(node.val);
    traverse(node.right);
  }

  traverse(root);

  return result;
}

/**
 * Solution 2
 *
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {TreeNode} root
 * @return {number[]}
 */
function solution2(root) {
  const result = [];
  const stack = [];
  let current = root;

  while (current !== null || stack.length > 0) {
    while (current !== null) {
      stack.push(current);
      current = current.left;
    }

    current = stack.pop();
    result.push(current.val);

    current = current.right;
  }

  return result;
}

/**
 * Solution 3
 *
 * Morris Traversal
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {TreeNode} root
 * @return {number[]}
 */
function solution3(root) {
  const result = [];
  let current = root;

  while (current !== null) {
    if (current.left === null) {
      result.push(current.val);
      current = current.right;
    } else {
      let predecessor = current.left;

      while (predecessor.right !== null && predecessor.right !== current) {
        predecessor = predecessor.right;
      }

      if (predecessor.right === null) {
        predecessor.right = current;
        current = current.left;
      } else {
        predecessor.right = null;
        result.push(current.val);
        current = current.right;
      }
    }
  }

  return result;
}
