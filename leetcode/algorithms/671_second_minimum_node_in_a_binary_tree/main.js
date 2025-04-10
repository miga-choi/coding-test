function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} node
 * @param {number} minVal
 * @return {number}
 */
var returnSecondMinimumValue = function (node, minVal) {
  if (!node) {
    return -1;
  }

  if (node.val > minVal) {
    return node.val;
  }

  const left = returnSecondMinimumValue(node.left, node.val);
  const right = returnSecondMinimumValue(node.right, node.val);

  if (left == -1) {
    return right;
  }
  if (right == -1) {
    return left;
  }

  return Math.min(left, right);
};

/**
 * @param {TreeNode} root
 * @return {number}
 */
var findSecondMinimumValue = function (root) {
  return returnSecondMinimumValue(root, root.val);
};

// Solution
var solution = function (root) {
  if (!root.left) return -1;

  const nodesQueue = [root];
  let secondMin = Infinity;
  const minVal = root.val;

  while (nodesQueue.length > 0) {
    const currentNode = nodesQueue.shift();

    if (currentNode.left) {
      nodesQueue.push(currentNode.left, currentNode.right);

      if (currentNode.left.val > minVal) {
        secondMin = Math.min(secondMin, currentNode.left.val);
      }

      if (currentNode.right.val > minVal) {
        secondMin = Math.min(secondMin, currentNode.right.val);
      }
    }
  }

  return secondMin === Infinity ? -1 : secondMin;
};
