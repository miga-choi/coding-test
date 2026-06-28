function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursiont: DFS
 *
 * Complexities:
 *   N - The Number of nodes in `root`
 *   H - THe Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function (root) {
  if (root === null) {
    return null;
  }

  const temp = root.left;
  root.left = invertTree(root.right);
  root.right = invertTree(temp);

  return root;
};


// Solution
/**
 * Solution 1
 *
 * Recursiont: DFS
 *
 * Complexities:
 *   N - The Number of nodes in `root`
 *   H - THe Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var solution1 = function (root) {
  if (root === null) {
    return null;
  }

  const temp = root.left;
  root.left = root.right;
  root.right = temp;

  solution1(root.left);
  solution1(root.right);

  return root;
};

/**
 * Solution 2
 *
 * Iteration: BFS (Queue)
 *
 * Complexities:
 *   N - The Number of nodes in `root`
 *   W - THe Width of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(W)
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var solution2 = function (root) {
  if (root === null) {
    return null;
  }

  const queue = [root];

  while (queue.length > 0) {
    const current = queue.shift();

    const temp = current.left;
    current.left = current.right;
    current.right = temp;

    if (current.left !== null) {
      queue.push(current.left);
    }
    if (current.right !== null) {
      queue.push(current.right);
    }
  }

  return root;
};
