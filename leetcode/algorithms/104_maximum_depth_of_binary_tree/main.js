function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
  if (!root) {
    return 0;
  }
  return returnDepth(0, root);
};

/**
 * @param {number} depth_
 * @param {TreeNode} node_
 * @return {number}
 */
var returnDepth = function (depth_, node_) {
  let depth = depth_ + 1;
  if (node_.left) {
    const leftDepth = returnDepth(depth_ + 1, node_.left);
    if (leftDepth > depth) {
      depth = leftDepth;
    }
  }
  if (node_.right) {
    const rightDepth = returnDepth(depth_ + 1, node_.right);
    if (rightDepth > depth) {
      depth = rightDepth;
    }
  }
  return depth;
};


// Best Solution
// Best Solution 1: Recursive
var bestSolution1 = function (root) {
  if (root === undefined || root === null) {
    return 0;
  }
  return Math.max(bestSolution1(root.left), bestSolution1(root.right)) + 1;
};

// Best Solution 2: Non-recursive
var bestSolution2 = function (root) {
  if (!root) {
    return 0;
  }
  const queue = [root];
  let depth = 0;
  while (queue.length !== 0) {
    depth++;
    const len = queue.length;
    for (let i = 0; i < len; i++) {
      if (queue[i].left) {
        queue.push(queue[i].left);
      }
      if (queue[i].right) {
        queue.push(queue[i].right);
      }
    }
    queue.splice(0, len);
  }
  return depth;
};
