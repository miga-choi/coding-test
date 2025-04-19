function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function (root) {
  const result = [];
  const nodes = [];

  if (root) {
    nodes.push(root);
    while (nodes.length > 0) {
      const node = nodes.pop();
      result.push(node.val);
      if (node.left) {
        nodes.push(node.left);
      }
      if (node.right) {
        nodes.push(node.right);
      }
    }
  }

  return result.reverse();
};


// Solution
// Solution 1: Iterative
var solution1 = function (root) {
  if (!root) {
    return [];
  }
  let stack = [], res = [];
  stack.push(root);
  while (stack.length) {
    let node = stack[stack.length - 1];
    if (node.left) {
      stack.push(node.left);
      node.left = null;
    } else if (node.right) {
      stack.push(node.right);
      node.right = null;
    } else {
      res.push(stack.pop().val);
    }
  }
  return res;
  // Time Complexity: O(n)
  // Space Complexity: O(n)
};

// Solution 2: Recursive
var solution2 = function (root) {
  let res = [];
  traverse(root);
  return res;

  function traverse(node) {
    if (!node) {
      return;
    }
    traverse(node.left);
    traverse(node.right);
    res.push(node.val);
  }
  // Time Complexity: O(n)
  // Space Complexity: O(n)
};
