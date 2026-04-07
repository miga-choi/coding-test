class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class ConvertSortedArrayToBinarySearchTree {
  /**
   * Divide-and-conquer
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(logᴺ)
   */
  TreeNode? sortedArrayToBST(List<int> nums) {
    if (nums.length == 0) return null;

    int mid = (nums.length / 2).floor();
    TreeNode root = TreeNode(
      nums[mid],
      sortedArrayToBST(nums.sublist(0, mid)),
      sortedArrayToBST(nums.sublist(mid + 1, nums.length)),
    );

    return root;
  }


  // Solution
  /**
   * Divide-and-conquer
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(logᴺ)
   */
  TreeNode? solution(List<int> nums) {
    if (nums.isEmpty) {
      return null;
    }

    return _buildBST(nums, 0, nums.length - 1);
  }

  TreeNode? _buildBST(List<int> nums, int left, int right) {
    if (left > right) {
      return null;
    }

    int mid = left + (right - left) ~/ 2;

    TreeNode root = TreeNode(nums[mid]);

    root.left = _buildBST(nums, left, mid - 1);
    root.right = _buildBST(nums, mid + 1, right);

    return root;
  }
}
