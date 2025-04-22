import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

class ConvertSortedArrayToBinarySearchTree {
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
      this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }

  public TreeNode sortedArrayToBST(int[] nums) {
    if (nums.length == 0) {
      return null;
    }

    int mid = Math.floorDiv(nums.length, 2);
    TreeNode root = new TreeNode(nums[mid]);

    root.left = sortedArrayToBST(Arrays.copyOfRange(nums, 0, mid));
    root.right = sortedArrayToBST(Arrays.copyOfRange(nums, mid + 1, nums.length));

    return root;
  }


  // Solution
  // Solution 1: Recursion
  public TreeNode solution1(int[] nums) {
    if (nums.length == 0) {
      return null;
    }
    TreeNode head = solution1_helper(nums, 0, nums.length - 1);
    return head;
  }

  public TreeNode solution1_helper(int[] nums, int low, int high) {
    if (low > high) {
      // Done
      return null;
    }
    int mid = (low + high) / 2;
    TreeNode node = new TreeNode(nums[mid]);
    node.left = solution1_helper(nums, low, mid - 1);
    node.right = solution1_helper(nums, mid + 1, high);
    return node;
  }

  // Solution 2: Recursion
  public TreeNode solution2(int[] nums) {
    return solution2_createBST(nums, 0, nums.length - 1);
  }

  private TreeNode solution2_createBST(int nums[], int l, int r) {
    if (l > r) {
      // Base Condition or Recursion Stoping Condition
      return null;
    }

    // so basically in this question we have to convert
    // sorted array to height balanced tree
    // so if we directly create tree in given sorted order
    // it will become linked list
    // so we have to take middle element as head value
    // such it will become height balanced tree

    // this is the formula to find mid value
    int mid = l + (r - l) / 2;

    // mid value or median
    TreeNode root = new TreeNode(nums[mid]);

    // assign the value for left of subtree that is l to mid -1 for given array
    root.left = solution2_createBST(nums, l, mid - 1);

    // assign the value for right go subtree that is mid+1 to r for given array
    root.right = solution2_createBST(nums, mid + 1, r);

    return root;
  }

  // Solution 3: Iteration
  public TreeNode solution3(int[] nums) {
    int len = nums.length;
    if (len == 0) {
      return null;
    }

    // 0 as a placeholder
    TreeNode head = new TreeNode(0);

    Deque<TreeNode> nodeStack = new LinkedList<TreeNode>() {
      {
        push(head);
      }
    };
    Deque<Integer> leftIndexStack = new LinkedList<Integer>() {
      {
        push(0);
      }
    };
    Deque<Integer> rightIndexStack = new LinkedList<Integer>() {
      {
        push(len - 1);
      }
    };

    while (!nodeStack.isEmpty()) {
      TreeNode currNode = nodeStack.pop();
      int left = leftIndexStack.pop();
      int right = rightIndexStack.pop();
      int mid = left + (right - left) / 2; // avoid overflow
      currNode.val = nums[mid];
      if (left <= mid - 1) {
        currNode.left = new TreeNode(0);
        nodeStack.push(currNode.left);
        leftIndexStack.push(left);
        rightIndexStack.push(mid - 1);
      }
      if (mid + 1 <= right) {
        currNode.right = new TreeNode(0);
        nodeStack.push(currNode.right);
        leftIndexStack.push(mid + 1);
        rightIndexStack.push(right);
      }
    }
    return head;
  }
}
