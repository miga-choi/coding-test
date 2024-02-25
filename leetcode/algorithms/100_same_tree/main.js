function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function (p, q) {
  return checkNode(p, q);
};

var checkNode = function (node1, node2) {
  if (!node1 && !node2) {
    return true;
  }

  if (!node1 || !node2) {
    return false;
  }

  if (node1.val !== node2.val) {
    return false;
  }

  return (
    checkNode(node1.left, node2.left) && checkNode(node1.right, node2.right)
  );
};


// Best Solution
// Best Solution 1:
function bestSolution1(p, q) {
  if (!p && !q) {
    return true;
  }
  if (!p || !q || p.val !== q.val) {
    return false;
  }

  return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
}

// Best Solution 2:
function bestSolution2(p, q) {
  return JSON.stringify(p) === JSON.stringify(q);
}

// Best Solution 3: Recursive (DFS) Preorder traversal
function bestSolution3(p, q) {
  // Base case: If both trees are empty, they are identical.
  if (p === null && q === null) {
    return true;
  }

  // If one of the trees is empty and the other is not, they are not identical.
  if (p === null || q === null) {
    return false;
  }

  // Compare the values of the current nodes.
  if (p.val !== q.val) {
    return false;
  }

  // Recursively check the left and right subtrees.
  return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
}

// Best Solution 4: Level-order traversal using Queues
function bestSolution4(p, q) {
  // Create queues for both trees.
  const queue1 = [p];
  const queue2 = [q];

  while (queue1.length > 0 && queue2.length > 0) {
    const node1 = queue1.shift();
    const node2 = queue2.shift();

    // If the values of the current nodes are not equal, the trees are not identical.
    if (!node1 && !node2) {
      continue;
    }
    if (!node1 || !node2 || node1.val !== node2.val) {
      return false;
    }

    // Add the left and right children of both nodes to their respective queues.
    queue1.push(node1.left);
    queue1.push(node1.right);
    queue2.push(node2.left);
    queue2.push(node2.right);
  }

  // If both queues are empty, the trees are identical.
  return queue1.length === 0 && queue2.length === 0;
}

// Best Solution 4: Level-order traversal using Stack
function bestSolution4(p, q) {
  const stack1 = [p];
  const stack2 = [q];

  while (stack1.length > 0 && stack2.length > 0) {
    const node1 = stack1.pop();
    const node2 = stack2.pop();

    if (!node1 && !node2) {
      continue;
    } else if (!node1 || !node2 || node1.val !== node2.val) {
      return false;
    }

    stack1.push(node1.left);
    stack2.push(node2.left);
    stack1.push(node1.right);
    stack2.push(node2.right);
  }

  return stack1.length === 0 && stack2.length === 0;
}

// Best Solution 4: Tree Hashing
function bestSolution4(p, q) {
  const hash1 = bestSolution4_computeTreeHash(p);
  const hash2 = bestSolution4_computeTreeHash(q);
  return hash1 === hash2;
}

function bestSolution4_computeTreeHash(node) {
  if (node === null) {
    return "null";
  }
  const leftHash = bestSolution4_computeTreeHash(node.left);
  const rightHash = bestSolution4_computeTreeHash(node.right);
  return `(${node.val}${leftHash}${rightHash})`;
}
