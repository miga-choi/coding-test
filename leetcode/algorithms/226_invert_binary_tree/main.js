function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Recursiont: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 *
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
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 *
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var solution1 = function (root) {
  if (root === null) {
    return null;
  }

  const invertedLeft = solution1(root.left);
  const invertedRight = solution1(root.right);

  root.left = invertedRight;
  root.right = invertedLeft;

  return root;
};

/**
 * Solution 2
 *
 * Iteration: BFS (Queue)
 * - Time Complexity: O(N)
 * - Space Complexity: O(W)
 *
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var solution2 = function (root) {
  if (root === null) {
    return null;
  }

  const queue = [root];

  while (queue.length > 0) {
    const currentNode = queue.shift();

    const temp = currentNode.left;
    currentNode.left = currentNode.right;
    currentNode.right = temp;

    if (currentNode.left !== null) {
      queue.push(currentNode.left);
    }
    if (currentNode.right !== null) {
      queue.push(currentNode.right);
    }
  }

  return root;
};
