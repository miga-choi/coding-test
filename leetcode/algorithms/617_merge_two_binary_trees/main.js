function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */
var mergeTrees = function (root1, root2) {
  if (root1 === null) {
    return root2;
  }
  if (root2 === null) {
    return root1;
  }

  return new TreeNode(
    root1.val + root2.val,
    mergeTrees(root1.left, root2.left),
    mergeTrees(root1.right, root2.right)
  );
};

// Solution
var solution = function (root1, root2) {
  // goal is to merge root2 to root1

  // if one of the node missing, return the other
  if (root1 === null) {
    return root2;
  }
  if (root2 === null) {
    return root1;
  }

  // if both nodes exist, sum the values
  root1.val += root2.val;

  // do the same thing for left and right branch
  root1.left = solution(root1.left, root2.left);
  root1.right = solution(root1.right, root2.right);

  // return the merged root1
  return root1;
};
