function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

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
var solution = function (root, isLeft) {
  if (!root) {
    return 0;
  }
  if (!root.left && !root.right && isLeft) {
    return root.val;
  }

  return solution(root.left, true) + solution(root.right, false);
};
