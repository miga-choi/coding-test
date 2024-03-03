function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

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


// Best Solution
// Best Solution 1:
var bestSolution1 = function (nums) {
  // Call the function recursively...
  return bestSolution1_convToBST(nums, 0, nums.length - 1);
};

// Create a function which will convert any particular range of given nums array...
// & return its corresponding BST root node....
var bestSolution1_convToBST = function (nums, beg, end) {
  // If beg > end, return NULL, as we receive a wrong range...
  if (beg > end) {
    return null;
  }
  // set the middle node...
  var mid = Math.ceil((beg + end) / 2);
  // Initialise root node with value same as nums[mid]...
  var root = new TreeNode(nums[mid]);
  // Assign left subtrees as the same function called on left subranges...
  root.left = bestSolution1_convToBST(nums, beg, mid - 1);
  // Assign right subtrees as the same function called on right subranges...
  root.right = bestSolution1_convToBST(nums, mid + 1, end);
  // Return the root node...
  return root;
};

// Best Solution 2: Intuitive
var bestSolution2 = function (nums) {
  if (!nums.length) {
    return null;
  }

  const mid = Math.floor(nums.length / 2);
  const root = new TreeNode(nums[mid]);

  // subtrees are BSTs as well
  root.left = sortedArrayToBST(nums.slice(0, mid));
  root.right = sortedArrayToBST(nums.slice(mid + 1));

  return root;
};
