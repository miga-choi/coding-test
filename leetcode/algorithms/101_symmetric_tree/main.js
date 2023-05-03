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
var isSymmetric = function (root) {
  if (!root) {
    return true;
  }
  return checkNode(root.left, root.right);
};
/**
 * @param {TreeNode} leftNode_
 * @param {TreeNode} rightNode_
 */
function checkNode(leftNode_, rightNode_) {
  if (!leftNode_ && !rightNode_) {
    return true;
  } else if ((leftNode_ && !rightNode_) || (!leftNode_ && rightNode_)) {
    return false;
  } else if (leftNode_.val !== rightNode_.val) {
    return false;
  } else {
    return (
      checkNode(leftNode_.left, rightNode_.right) &&
      checkNode(leftNode_.right, rightNode_.left)
    );
  }
}

// Best Solution
var bestSolution = function (root) {
  // Special case...
  if (!root) return true;
  // Return the function recursively...
  return isSame(root.left, root.right);
};

// A tree is called symmetric if the left subtree must be a mirror reflection of the right subtree...
var isSame = function (leftroot, rightroot) {
  // If both root nodes are null pointers, return true...
  // If exactly one of them is a null node, return false...
  // If root nodes haven't same value, return false...
  if (
    (!leftroot && rightroot) ||
    (leftroot && !rightroot) ||
    (leftroot && rightroot && leftroot.val !== rightroot.val)
  )
    return false;
  // Return true if the values of root nodes are same and left as well as right subtrees are symmetric...
  if (leftroot && rightroot)
    return (
      isSame(leftroot.left, rightroot.right) &&
      isSame(leftroot.right, rightroot.left)
    );
  return true;
};
