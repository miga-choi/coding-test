function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {string}
 */
var tree2str = function (root) {
  if (!root) {
    return "";
  }

  if (!root.left && !root.right) {
    return `${root.val}`;
  }

  let left = "()";
  if (root.left) {
    left = `(${tree2str(root.left)})`;
  }

  let right = "";
  if (root.right) {
    right = `(${tree2str(root.right)})`;
  }

  return `${root.val}${left}${right}`;
};


// Best Solution
// Best Solution 1:
var bestSolution1 = function (root) {
  let res = [];
  dfs(root, res);
  return res.join("");

  function dfs(t, res) {
    if (t === null) {
      return;
    }

    res.push(t.val);

    if (t.left === null && t.right === null) {
      return;
    }

    res.push("(");
    dfs(t.left, res);
    res.push(")");

    if (t.right !== null) {
      res.push("(");
      dfs(t.right, res);
      res.push(")");
    }
  }
};

// Best Solution 2:
var bestSolution2 = function (root) {
  function dfs(node) {
    if (!node) {
      return "";
    }
    if (node.right) {
      return `${node.val}(${dfs(node.left)})(${dfs(node.right)})`;
    }
    if (node.left) {
      return `${node.val}(${dfs(node.left)})`;
    }
    return `${node.val}`;
  }

  return dfs(root);
};

// Best Solution 3:
var bestSolution3 = function (root) {
  // Check if the tree is empty
  if (!root) {
    return "";
  }

  // Initialize an empty result string
  let res = "";
  // Initialize a stack for iterative traversal
  const stack = [root];
  // Use a set to track visited nodes
  const visited = new Set();

  // Iterate through the tree using a stack
  while (stack.length > 0) {
    // Get the current node from the top of the stack
    const cur = stack[stack.length - 1];

    // If the current node is already visited, pop it from the stack and close the parenthesis
    if (visited.has(cur)) {
      stack.pop();
      res += ")";
    } else {
      // If the current node is not visited, mark it as visited and add its value to the result
      visited.add(cur);
      res += `(${cur.val}`;

      // If the current node has no left child and a right child, add an empty pair of parentheses
      if (!cur.left && cur.right) {
        res += "()";
      }

      // Add the right child to the stack if it exists
      if (cur.right) {
        stack.push(cur.right);
      }

      // Add the left child to the stack if it exists
      if (cur.left) {
        stack.push(cur.left);
      }
    }
  }

  // Return the result string with leading '(' and trailing ')' removed
  return res.substring(1, res.length - 1);
};
