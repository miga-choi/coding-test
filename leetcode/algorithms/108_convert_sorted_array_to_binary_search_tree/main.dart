class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class ConvertSortedArrayToBinarySearchTree {
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
  TreeNode? solution(List<int> nums) {
    if (nums.isEmpty) {
      return null;
    }

    int mid = nums.length ~/ 2;
    TreeNode root = TreeNode();
    root.val = nums[mid];
    root.left = solution(nums.sublist(0, mid));
    root.right = solution(nums.sublist(mid + 1));

    return root;
  }
}
