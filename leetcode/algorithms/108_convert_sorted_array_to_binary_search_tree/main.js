function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * Divide-and-conquer
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function (nums) {
  if (!nums || !nums.length) {
    return null;
  }

  const mid = Math.floor(nums.length / 2);

  const root = new TreeNode(nums[mid]);
  root.left = sortedArrayToBST(nums.slice(0, mid));
  root.right = sortedArrayToBST(nums.slice(mid + 1));

  return root;
};


// Solution
/**
 * Divide-and-conquer
 *
 * Complexities:
 *   N - Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(logᴺ)
 */
var solution = function (nums) {
  if (!nums || nums.length === 0) {
    return null;
  }

  function buildBST(left, right) {
    if (left > right) {
      return null;
    }

    const mid = Math.floor((left + right) / 2);

    const node = new TreeNode(nums[mid]);

    node.left = buildBST(left, mid - 1);
    node.right = buildBST(mid + 1, right);

    return node;
  }

  return buildBST(0, nums.length - 1);
};
