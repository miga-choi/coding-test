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


// Best Solution
// Best Solution 1: Iteravtive Post-order Traverse
var bestSolution1 = function (root) {
  const res = [], stack = [root];
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

// Best Solution 2: Recursive Post-order Traverse
var bestSolution2 = function (root) {
  const res = [];
  traverse(root);
  return res;

  function traverse(node) {
    if (!node) {
      return;
    }
    for (child of node.children) {
      traverse(child);
    }
    res.push(node.val);
  }
};
