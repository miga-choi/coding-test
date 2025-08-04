/**
 * Graph & Hash Map & Vector
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {number[][]} adjacentPairs
 * @return {number[]}
 */
var restoreArray = function (adjacentPairs) {
  const adjacentMap = new Map();

  for (const [v1, v2] of adjacentPairs) {
    if (adjacentMap.has(v1)) {
      adjacentMap.get(v1).push(v2);
    } else {
      adjacentMap.set(v1, [v2]);
    }

    if (adjacentMap.has(v2)) {
      adjacentMap.get(v2).push(v1);
    } else {
      adjacentMap.set(v2, [v1]);
    }
  }

  let start;
  for (const [key, value] of adjacentMap.entries()) {
    if (value.length == 1) {
      start = key;
      break;
    }
  }

  const length = adjacentPairs.length + 1;
  let curr = start;
  let prev = -100001;
  const result = new Array();

  for (let i = 0; i < length; i++) {
    result.push(curr);

    const neighbors = adjacentMap.get(curr);

    let next;
    if (neighbors.length === 1 || neighbors[0] !== prev) {
      next = neighbors[0];
    } else {
      next = neighbors[1];
    }

    prev = curr;
    curr = next;
  }

  return result;
};


// Solution
var solution = function (adjacentPairs) {
  const graph = new Map();

  for (const [u, v] of adjacentPairs) {
    if (!graph.has(u)) {
      graph.set(u, []);
    }
    if (!graph.has(v)) {
      graph.set(v, []);
    }
    graph.get(u).push(v);
    graph.get(v).push(u);
  }

  let result = [];

  for (const [node, neighbors] of graph.entries()) {
    if (neighbors.length === 1) {
      result = [node, neighbors[0]];
      break;
    }
  }

  while (result.length < adjacentPairs.length + 1) {
    const [last, prev] = [result[result.length - 1], result[result.length - 2]];
    const candidates = graph.get(last);
    const nextElement = candidates[0] !== prev ? candidates[0] : candidates[1];
    result.push(nextElement);
  }

  return result;
};
