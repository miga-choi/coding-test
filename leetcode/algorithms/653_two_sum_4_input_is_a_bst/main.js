function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} node
 * @param {number[]} valArray
 * @return {void}
 */
var inorder = function (node, valArray) {
  if (node) {
    inorder(node.left, valArray);
    valArray.push(node.val);
    inorder(node.right, valArray);
  }
};

/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {boolean}
 */
var findTarget = function (root, k) {
  const valArray = [];

  inorder(root, valArray);

  let left = 0;
  let right = valArray.length - 1;

  while (left < right) {
    const sum = valArray[left] + valArray[right];
    if (sum < k) {
      left++;
    } else if (sum > k) {
      right--;
    } else {
      return true;
    }
  }

  return false;
};

// Solution: DFS with a Set
var solution = function (root, k) {
  if (!root) {
    return false;
  }

  const set = new Set();
  const stack = [root];

  while (stack.length) {
    const node = stack.pop();
    if (set.has(k - node.val)) {
      return true;
    }
    set.add(node.val);
    if (node.right) {
      stack.push(node.right);
    }
    if (node.left) {
      stack.push(node.left);
    }
  }
  return false;
};
