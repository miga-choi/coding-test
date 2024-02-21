function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
  const totalRoots = [];
  const result = [];

  while (root || totalRoots.length > 0) {
    if (root) {
      totalRoots.push(root);
      root = root.left;
    } else {
      root = totalRoots.pop();
      result.push(root.val);
      root = root.right;
    }
  }

  return result;
};


// Best Solution
// Best Solution 1: Iteration
function bestSolution1(root) {
  const stack = [];
  const res = [];

  while (root || stack.length) {
    if (root) {
      stack.push(root);
      root = root.left;
    } else {
      root = stack.pop();
      res.push(root.val);
      root = root.right;
    }
  }

  return res;
}

// Best Solution 2: DFS
function bestSolution2(root) {
  const result = [];
  helper(root, result);
  return result;
}

function helper(root, result) {
  if (root !== null) {
    helper(root.left, result);
    result.push(root.val);
    helper(root.right, result);
  }
}

// Best Solution 3: Recursion
function bestSolution3(root) {
  const res = [];

  function inorder(node) {
    if (!node) {
      return;
    }
    inorder(node.left);
    res.push(node.val);
    inorder(node.right);
  }

  inorder(root);
  return res;
}

// Best Solution 4: Stack
function bestSolution4(root) {
  // Initialize an empty array to store the result (in-order traversal)
  const res = [];

  // Initialize an empty stack for iterative traversal
  const stack = [];

  // Loop until either the current node is not null or the stack is not empty
  while (root || stack.length > 0) {
    // Traverse to the leftmost node and push each encountered node onto the stack
    while (root) {
      stack.push(root);
      root = root.left;
    }

    // Pop the last node from the stack (most recently left-visited node)
    root = stack.pop();

    // Append the value of the popped node to the result array
    res.push(root.val);

    // Move to the right subtree to continue the in-order traversal
    root = root.right;
  }

  // Return the final result array
  return res;
}
