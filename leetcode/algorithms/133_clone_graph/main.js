function Node(val, neighbors) {
  this.val = val === undefined ? 0 : val;
  this.neighbors = neighbors === undefined ? [] : neighbors;
}

/**
 * DFS + HashMap
 *
 * Complexities:
 *   V - Number of Vertex in `s`
 *   E - Number of Edge in `s`
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V)
 */
const nodeMap = new Map();

/**
 * @param {Node} node
 * @return {Node}
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
 * DFS
 *
 * Complexities:
 *   V - Number of Vertex in `s`
 *   E - Number of Edge in `s`
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V)
 */
/**
 * @param {Node} node
 * @return {Node}
 */
var solution1 = function (node) {
  if (!node) {
    return null;
  }

  const visited = new Map();

  function dfs(originalNode) {
    if (visited.has(originalNode)) {
      return visited.get(originalNode);
    }

    const cloneNode = new Node(originalNode.val);

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
 * BFS + Queue
 *
 * Complexities:
 *   V - Number of Vertex in `s`
 *   E - Number of Edge in `s`
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V)
 */
/**
 * @param {Node} node
 * @return {Node}
 */
var solution2 = function (node) {
  if (!node) {
    return null;
  }

  const visited = new Map();
  const queue = [node];

  visited.set(node, new Node(node.val));

  while (queue.length > 0) {
    const current = queue.shift();

    for (const neighbor of current.neighbors) {
      if (!visited.has(neighbor)) {
        visited.set(neighbor, new Node(neighbor.val));
        queue.push(neighbor);
      }

      visited.get(current).neighbors.push(visited.get(neighbor));
    }
  }

  return visited.get(node);
};
