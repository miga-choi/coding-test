function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function (root) {
  if (!root) {
    return [];
  }

  if (!root.left && !root.right) {
    return [`${root.val}`];
  }

  const leftArray = binaryTreePaths(root.left);
  const rightArray = binaryTreePaths(root.right);

  const left = leftArray.map((v_) => `${root.val}->${v_}`);
  const right = rightArray.map((v_) => `${root.val}->${v_}`);

  return [...left, ...right];
};


// Solution
var solution = function (root) {
  if (root === null) {
    // If null return an empty array
    return [];
  } else if (root.left === null && root.right === null) {
    // If no children return the nodes value itself as a string within an array
    return [`${root.val}`];
  } else {
    // For all child paths add the root to their head one by one.
    let left = bestSolution(root.left).map((x) => root.val + "->" + x);
    let right = bestSolution(root.right).map((x) => root.val + "->" + x);

    // return the array with the root value attached
    return [...left, ...right];
  }
};
