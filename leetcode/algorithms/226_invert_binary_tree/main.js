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
 * @return {TreeNode}
 */
var invertTree = function (root) {
  if (root) {
    if (root.left || root.right) {
      const tempNode = invertTree(root.left);
      root.left = invertTree(root.right);
      root.right = tempNode;
    }
  }
  return root;
};


// Best Solution
var bestSolution = function (root) {
  // Base case...
  if (root == null) {
    return root;
  }
  // Call the function recursively for the left subtree...
  bestSolution(root.left);
  // Call the function recursively for the right subtree...
  bestSolution(root.right);
  // swapping process...
  const curr = root.left;
  root.left = root.right;
  root.right = curr;
  return root; // Return the root...
};
