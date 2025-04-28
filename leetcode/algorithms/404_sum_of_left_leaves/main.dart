class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class SumOfLeftLeaves {
  // My Solution 1
  int sumOfLeftLeaves1(TreeNode? root) {
    int sum = 0;
    if (root != null) {
      if (root.left != null) {
        if (root.left!.left == null && root.left!.right == null) {
          sum += root.left!.val;
        }
      }
      sum += sumOfLeftLeaves1(root.left) + sumOfLeftLeaves1(root.right);
    }
    return sum;
  }

  // My Solution 2
  int addLeftVal(TreeNode? root, bool isLeft) {
    int sum = 0;
    if (root != null) {
      if (isLeft && root.left == null && root.right == null) {
        sum += root.val;
      } else {
        sum += addLeftVal(root.left, true) + addLeftVal(root.right, false);
      }
    }
    return sum;
  }

  int sumOfLeftLeaves2(TreeNode? root) {
    if (root == null) {
      return 0;
    }
    return addLeftVal(root.left, true) + addLeftVal(root.right, false);
  }


  // Solution
  int total = 0;
  bool isLeft = false;

  int solution(TreeNode? root) {
    if (root?.left == null && root?.right == null) {
      if (isLeft) {
        total += root?.val ?? 0;
      }
    }
    if (root?.left != null) {
      isLeft = true;
      solution(root!.left);
    }
    if (root?.right != null) {
      isLeft = false;
      solution(root!.right);
    }

    return total;
  }
}
