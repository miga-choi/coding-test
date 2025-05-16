function Node(val, children) {
  this.val = val;
  this.children = children;
}

/**
 * @param {Node|null} root
 * @return {number}
 */
var maxDepth = function (root) {
  if (!root) {
    return 0;
  }
  let max = 0;
  for (const child of root.children) {
    max = Math.max(max, maxDepth(child));
  }
  return max + 1;
};


// Solution
// Solution 1: DFS Recursion
var solution1 = function (root) {
  if (!root) {
    return 0;
  }
  let max = 0;
  for (let child of root.children) {
    max = Math.max(max, solution1(child));
  }
  return max + 1;
};

// Solution 2: DFS Recursion with helper function
var solution2 = function (root) {
  if (!root) {
    return 0;
  }
  let max = -1;

  const helper = (node, depth) => {
    if (depth > max) {
      max = depth;
    }
    for (let c of node.children) {
      helper(c, depth + 1);
    }
  };

  helper(root, 1);
  return max;
};

// Solution 3: BFS
var solution3 = function (root) {
  if (!root) {
    return 0;
  }
  // Note: it is not advised to use array as queue
  let queue = [],
    depthCount = 0;
  queue.push(root);

  while (queue.length > 0) {
    let len = queue.length;

    for (let i = 0; i < len; i++) {
      let node = queue.shift();
      for (let child of node.children) {
        queue.push(child);
      }
    }
    depthCount++;
  }
  return depthCount;
};
