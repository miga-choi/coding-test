function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function (root) {
  return getMinDepth(root);
};

/**
 * @param {number} depth_
 * @param {TreeNode} node_
 * @return {number}
 */
const getMinDepth = (node_) => {
  if (!node_) {
    return 0;
  }

  if (!node_.left) {
    return getMinDepth(node_.right) + 1;
  }

  if (!node_.right) {
    return getMinDepth(node_.left) + 1;
  }

  return Math.min(getMinDepth(node_.left), getMinDepth(node_.right)) + 1;
};


// Solution
// Solution 1
var solution1 = function (root) {
  // Base case...
  // If the subtree is empty i.e. root is NULL, return depth as 0...
  if (root == null) {
    return 0;
  }

  // If the both subtrees are empty...
  if (root.left == null && root.right == null) {
    return 1;
  }

  // If the left subtree is empty, return the depth of right subtree after adding 1 to it...
  if (root.left == null) {
    return solution1(root.right) + 1;
  }

  // If the right subtree is empty, return the depth of left subtree after adding 1 to it...
  if (root.right == null) {
    return solution1(root.left) + 1;
  }

  // When the two child function return its depth...
  // Pick the minimum out of these two subtrees and return this value after adding 1 to it...
  return Math.min(solution1(root.left), solution1(root.right)) + 1; // Adding 1 is the current node which is the parent of the two subtrees...
};

// Solution 2
var solution2 = function (root) {
  if (!root) {
    return 0;
  }
  let depth = 1;
  let queue = [root];
  if (!root.left && !root.right) {
    return depth;
  }

  while (queue.length > 0) {
    let queueLength = queue.length;

    for (let i = 0; i < queueLength; i++) {
      let node = queue.shift();

      if (!node.left && !node.right) {
        return depth;
      } else {
        if (node.left) queue.push(node.left);
        if (node.right) queue.push(node.right);
      }
    }

    depth++;
  }

  return depth;
};
