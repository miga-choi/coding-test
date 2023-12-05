function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function (root, subRoot) {
  /**
   * @param {TreeNode} node
   * @return {boolean}
   */
  function checkNode(node) {
    if (!node) {
      return false;
    }
    if (compareNode(node, subRoot)) {
      return true;
    } else {
      return checkNode(node.left) || checkNode(node.right);
    }
  }

  /**
   * @param {TreeNode} node1
   * @param {TreeNode} node2
   * @return {boolean}
   */
  function compareNode(node1, node2) {
    if (!node1 && !node2) {
      return true;
    } else if (!node1 || !node2) {
      return false;
    } else {
      return (
        node1.val === node2.val &&
        compareNode(node1.left, node2.left) &&
        compareNode(node1.right, node2.right)
      );
    }
  }

  return checkNode(root);
};


// Best Solution
var bestSolution1 = function (root, subRoot) {
  if (!root) return !subRoot;
  return (
    isEqual(root, subRoot) ||
    bestSolution1(root.left, subRoot) ||
    bestSolution1(root.right, subRoot)
  );
};

function isEqual(root1, root2) {
  if (!root1 || !root2) return !root1 && !root2;
  if (root1.val !== root2.val) return false;
  return isEqual(root1.left, root2.left) && isEqual(root1.right, root2.right);
}

// DFS
var bestSolution2 = function (root, subRoot) {
  const areEqual = (node1, node2) => {
    if (!node1 || !node2) {
      return !node1 && !node2;
    }
    if (node1.val !== node2.val) {
      return false;
    }
    return (
      areEqual(node1.left, node2.left) && areEqual(node1.right, node2.right)
    );
  };
  const dfs = (node) => {
    if (!node) {
      return false;
    }
    if (areEqual(node, subRoot)) {
      return true;
    }
    return dfs(node.left) || dfs(node.right);
  };
  return dfs(root);
};

// BFS
var bestSolution3 = function (root, subRoot) {
  const areEqual = (tree, subTree) => {
    const queue = [[tree, subTree]];
    while (queue.length) {
      const [node1, node2] = queue.pop();
      if (!node1 && !node2) {
        continue;
      }
      if (!node1 || !node2 || node1.val !== node2.val) {
        return false;
      }
      queue.push([node1.right, node2.right], [node1.left, node2.left]);
    }
    return true;
  };
  const queue = [root];
  while (queue.length) {
    const node = queue.pop();
    if (!node) {
      continue;
    }
    if (areEqual(node, subRoot)) {
      return true;
    }
    queue.push(node.right, node.left);
  }
  return false;
};

// Hybrid
const bestSolution4 = (root, subRoot) => {
  const areEqual = (node1, node2) => {
    if (!node1 || !node2) {
      return !node1 && !node2;
    }
    if (node1.val !== node2.val) {
      return false;
    }
    return (
      areEqual(node1.left, node2.left) && areEqual(node1.right, node2.right)
    );
  };
  const queue = [root];
  while (queue.length) {
    const node = queue.pop();
    if (!node) {
      continue;
    }
    if (areEqual(node, subRoot)) {
      return true;
    }
    queue.push(node.right, node.left);
  }
  return false;
};
