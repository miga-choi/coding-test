function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var getMinimumDifference = function (root) {
  const array = [];
  let result = 10 ** 5 + 1;

  /**
   * @param {TreeNode} node
   */
  const bstToArray = (node) => {
    if (node) {
      bstToArray(node.left);
      array.push(node.val);
      bstToArray(node.right);
    }
  };

  bstToArray(root);

  for (let i = 1; i < array.length; i++) {
    const diff = Math.abs(array[i - 1] - array[i]);
    if (diff < result) {
      result = diff;
    }
  }

  return result;
};


// Best Solution
var bestSolution = function (root) {
  // Converting tree to an sorted array
  const arr = toArray(root);
  let out = Infinity;
  let i = 1;
  // Now, simply finding the difference
  while (i < arr.length) {
    let diff = Math.abs(arr[i - 1] - arr[i]);
    if (diff < out) {
      out = diff;
    }
    i++;
  }
  return out;
};

function toArray(root, out = []) {
  if (root) {
    toArray(root.left, out);
    out.push(root.val);
    toArray(root.right, out);
    return out;
  }
}
