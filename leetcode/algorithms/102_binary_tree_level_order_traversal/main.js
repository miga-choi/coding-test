function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * BFS
 *
 * Complexities:
 *   N - Size of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function (root) {
  const result = [];

  if (!root) {
    return result;
  }

  const q = [];
  q.push(root);

  while (q.length > 0) {
    const size = q.length;
    const array = [];

    for (let i = 0; i < size; i++) {
      const node = q.shift();

      array.push(node.val);

      if (node.left) {
        q.push(node.left);
      }
      if (node.right) {
        q.push(node.right);
      }
    }

    result.push(array);
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * BFS
 *
 * Complexities:
 *   N - Size of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var solution1 = function (root) {
  if (!root) {
    return [];
  }

  const result = [];
  const queue = [root];

  while (queue.length > 0) {
    const levelSize = queue.length;
    const currentLevel = [];

    for (let i = 0; i < levelSize; i++) {
      const currentNode = queue.shift();
      currentLevel.push(currentNode.val);

      if (currentNode.left) {
        queue.push(currentNode.left);
      }
      if (currentNode.right) {
        queue.push(currentNode.right);
      }
    }

    result.push(currentLevel);
  }

  return result;
};

/**
 * Solution 2
 *
 * DFS
 *
 * Complexities:
 *   N - Size of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var solution2 = function (root) {
  const result = [];

  function dfs(node, level) {
    if (!node) {
      return;
    }

    if (result.length === level) {
      result.push([]);
    }

    result[level].push(node.val);

    dfs(node.left, level + 1);
    dfs(node.right, level + 1);
  }

  dfs(root, 0);
  return result;
};
