/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function (root) {
  return checkDepth(root) === -1 ? false : true;
};

/**
 * @param {TreeNode} root_
 * @return {number}
 */
const checkDepth = (root_) => {
  if (!root_) {
    return 0;
  }

  const leftDepth = checkDepth(root_.left);
  const rightDepth = checkDepth(root_.right);

  if (leftDepth === -1 || rightDepth === -1) {
    return -1;
  }

  if (leftDepth - rightDepth > 1 || rightDepth - leftDepth > 1) {
    return -1;
  }

  if (leftDepth >= rightDepth) {
    return leftDepth + 1;
  } else {
    return rightDepth + 1;
  }
};

// Best Solution
var bestSolution = function (root) {
  // If the tree is empty, we can say it’s balanced...
  if (root == null) return true;
  // Height Function will return -1, when it’s an unbalanced tree...
  if (Height(root) == -1) return false;
  return true;
};

// Create a function to return the “height” of a current subtree using recursion...
var Height = function (root) {
  // Base case...
  if (root == null) return 0;
  // Height of left subtree...
  let leftHeight = Height(root.left);
  // Height of height subtree...
  let rightHight = Height(root.right);
  // In case of left subtree or right subtree unbalanced, return -1...
  if (leftHeight == -1 || rightHight == -1) return -1;
  // If their heights differ by more than ‘1’, return -1...
  if (Math.abs(leftHeight - rightHight) > 1) return -1;
  // Otherwise, return the height of this subtree as max(leftHeight, rightHight) + 1...
  return Math.max(leftHeight, rightHight) + 1;
};
