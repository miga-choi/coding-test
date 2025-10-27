function _Node(val, neighbors) {
  this.val = val === undefined ? 0 : val;
  this.neighbors = neighbors === undefined ? [] : neighbors;
}

/**
 * Recursion: DFS + Hash table
 * - Time Complexity: O(N + E)
 * - Space Complexity: O(N)
 */
const nodeMap = new Map();

/**
 * @param {_Node} node
 * @return {_Node}
 */
var cloneGraph = function (node) {
  if (node === null) {
    return null;
  }

  if (nodeMap.has(node)) {
    return nodeMap.get(node);
  }

  const result = new _Node(node.val);
  nodeMap.set(node, result);

  for (const neighbor of node.neighbors) {
    result.neighbors.push(cloneGraph(neighbor));
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Recursion: DFS + Hash table
 * - Time Complexity: O(N + E)
 * - Space Complexity: O(N)
 */
/**
 * @param {_Node} node
 * @return {_Node}
 */
var solution1 = function (node) {
  const visited = new Map();

  function dfs(originalNode) {
    if (originalNode === null) {
      return null;
    }

    if (visited.has(originalNode)) {
      return visited.get(originalNode);
    }

    const cloneNode = new _Node(originalNode.val);
    visited.set(originalNode, cloneNode);

    for (const neighbor of originalNode.neighbors) {
      cloneNode.neighbors.push(dfs(neighbor));
    }

    return cloneNode;
  }

  return dfs(node);
};

/**
 * Solution 2
 *
 * Iteration: BFS + Hash table + Queue
 * - Time Complexity: O(N + E)
 * - Space Complexity: O(N)
 */
/**
 * @param {_Node} node
 * @return {_Node}
 */
var solution2 = function (node) {
  if (node === null) {
    return null;
  }

  const visited = new Map();
  const queue = [node];

  visited.set(node, new _Node(node.val));

  while (queue.length > 0) {
    const currentNode = queue.shift();

    for (const neighbor of currentNode.neighbors) {
      if (!visited.has(neighbor)) {
        visited.set(neighbor, new _Node(neighbor.val));
        queue.push(neighbor);
      }

      visited.get(currentNode).neighbors.push(visited.get(neighbor));
    }
  }

  return visited.get(node);
};
