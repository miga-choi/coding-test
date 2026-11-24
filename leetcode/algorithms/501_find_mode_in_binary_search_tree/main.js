/**
 * Definition for a binary tree node.
 */
function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * In-order Traversal to Array + Two-Pass Run Counting
 *
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(n)
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var findMode = function (root) {
  const map = new Map();

  /**
   * @param {TreeNode} node
   * @returns
   */
  const checkVal = (node) => {
    if (!node) {
      return;
    }
    if (node.left) {
      checkVal(node.left);
    }
    if (node.right) {
      checkVal(node.right);
    }
    if (!map.get(node.val)) {
      map.set(node.val, 1);
    } else {
      map.set(node.val, map.get(node.val) + 1);
    }
  };

  checkVal(root);

  return [...map.entries()]
    .filter((v) => v[1] === Math.max(...map.values()))
    .map(([k]) => k);
};


// Solution
/**
 * Solution 1
 *
 * Hash Map + DFS
 *
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(n)
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var solution1 = function (root) {
  const freq = new Map();

  const dfs = (node) => {
    if (!node) {
      return;
    }

    freq.set(node.val, (freq.get(node.val) ?? 0) + 1);
    dfs(node.left);
    dfs(node.right);
  };

  dfs(root);

  let maxCount = 0;
  for (const c of freq.values()) {
    if (c > maxCount) {
      maxCount = c;
    }
  }

  const modes = [];
  for (const [val, c] of freq) {
    if (c === maxCount) {
      modes.push(val);
    }
  }

  return modes;
};

/**
 * Solution 2
 *
 * In-order Traversal (Sorted Sequence Counting)
 *
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   h - The Height of `root`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(h)
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var solution2 = function (root) {
  let prev = null;
  let count = 0;
  let maxCount = 0;
  let modes = [];

  const visit = (val) => {
    count = val === prev ? count + 1 : 1;
    prev = val;

    if (count > maxCount) {
      maxCount = count;
      modes = [val];
    } else if (count === maxCount) {
      modes.push(val);
    }
  };

  const inorder = (node) => {
    if (!node) {
      return;
    }

    inorder(node.left);
    visit(node.val);
    inorder(node.right);
  };

  inorder(root);

  return modes;
};

/**
 * Solution 3
 *
 * Morris In-order Traversal
 *
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   h - The Height of `root`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var solution3 = function (root) {
  let prev = null, count = 0, maxCount = 0, modes = [];

  const visit = (val) => {
    count = val === prev ? count + 1 : 1;
    prev = val;

    if (count > maxCount) {
      maxCount = count;
      modes = [val];
    } else if (count === maxCount) {
      modes.push(val);
    }
  };

  let cur = root;
  while (cur) {
    if (!cur.left) {
      visit(cur.val);
      cur = cur.right;
    } else {
      let pred = cur.left;

      while (pred.right && pred.right !== cur) {
        pred = pred.right;
      }

      if (!pred.right) {
        pred.right = cur;
        cur = cur.left;
      } else {
        pred.right = null;
        visit(cur.val);
        cur = cur.right;
      }
    }
  }

  return modes;
};
