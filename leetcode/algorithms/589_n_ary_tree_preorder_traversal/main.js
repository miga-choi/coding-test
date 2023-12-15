function Node(val, children) {
  this.val = val;
  this.children = children;
}

/**
 * @param {Node|null} root
 * @return {number[]}
 */
var preorder = function (root) {
  const result = [];

  /**
   * @param {Node|null} node
   * @return {void}
   */
  function getVal(node) {
    if (!node) {
      return;
    }
    result.push(node.val);
    for (const child of node.children) {
      getVal(child);
    }
  }

  getVal(root);

  return result;
};


// Best Solution
// Best Solution 1
var bestSolution1 = function (root, ans = []) {
  if (!root) {
    return ans;
  }
  ans.push(root.val);
  for (let child of root.children) {
    bestSolution1(child, ans);
  }
  return ans;
};

// Best Solution 2
var bestSolution2 = function (root) {
  const result = [];
  function traverse(tree) {
    if (!tree) {
      return result;
    }
    result.push(tree.val);
    for (let i = 0; i < tree.children.length; i++) {
      traverse(tree.children[i]);
    }
    return result;
  }
  return traverse(root);
};

// Best Solution 3
var bestSolution3 = function (root) {
  const stack = [];
  const result = [];
  if (!root) {
    return result;
  }
  stack.push(root);
  while (stack.length) {
    const node = stack.pop();
    result.push(node.val);
    for (let i = node.children.length - 1; i >= 0; i--) {
      stack.push(node.children[i]);
    }
  }
  return result;
};
