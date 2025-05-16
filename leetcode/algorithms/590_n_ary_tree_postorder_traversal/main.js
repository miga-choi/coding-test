function Node(val, children) {
  this.val = val;
  this.children = children;
}

/**
 * @param {Node|null} root
 * @param {number[]} result
 * @return {number[]}
 */
var postorder = function (root, result = []) {
  if (!root) {
    return result;
  }

  for (const child of root.children) {
    postorder(child, result);
  }

  result.push(root.val);

  return result;
};


// Solution
// Solution 1: Iteravtive Post-order Traverse
var solution1 = function (root) {
  const res = [],
    stack = [root];

  while (stack.length) {
    const curr = stack.pop();
    if (!curr) {
      continue;
    }
    res.push(curr.val);
    stack.push(...curr.children);
  }

  return res.reverse();
};

// Solution 2: Recursive Post-order Traverse
var solution2 = function (root) {
  const res = [];

  function traverse(node) {
    if (!node) {
      return;
    }
    for (child of node.children) {
      traverse(child);
    }
    res.push(node.val);
  }

  traverse(root);

  return res;
};
