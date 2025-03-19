function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var averageOfLevels = function (root) {
  const result = [], queue = [];
  let left = 0, right = 0;

  queue[right++] = root;
  while (left < right) {
    const nodeCount = right - left;
    let sum = 0;
    for (let i = 0; i < nodeCount; i++) {
      const node = queue[left++];
      sum += node.val;
      if (node.left) {
        queue[right++] = node.left;
      }
      if (node.right) {
        queue[right++] = node.right;
      }
    }
    result.push(sum / nodeCount);
  }

  return result;
};

// Solution
var solution = function (root) {
  let q = [root], ans = [];
  while (q.length) {
    let qlen = q.length, row = 0;
    for (let i = 0; i < qlen; i++) {
      let curr = q.shift();
      row += curr.val;
      if (curr.left) {
        q.push(curr.left);
      }
      if (curr.right) {
        q.push(curr.right);
      }
    }
    ans.push(row / qlen);
  }
  return ans;
};
