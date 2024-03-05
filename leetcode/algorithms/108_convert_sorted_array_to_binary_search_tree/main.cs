using System;
using System.Linq;

public class ConvertSortedArrayToBinarySearchTree
{
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public TreeNode SortedArrayToBST(int[] nums)
    {
        if (nums.Length == 0)
        {
            return null;
        }

        TreeNode node = new TreeNode(nums[nums.Length / 2]);
        node.left = SortedArrayToBST(nums.Take(nums.Length / 2).ToArray());
        node.right = SortedArrayToBST(nums.Skip(nums.Length / 2 + 1).ToArray());

        return node;
    }


    // Best Solution
    // Best Solution 1: Recursion
    public TreeNode bestSolution1(int[] nums)
    {
        if (nums == null || nums.Length == 0)
        {
            return null;
        }
        return bestSolution1_constructBSTRecursive(nums, 0, nums.Length - 1);
    }

    private TreeNode bestSolution1_constructBSTRecursive(int[] nums, int left, int right)
    {
        if (left > right)
        {
            return null;
        }
        int mid = left + (right - left) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = bestSolution1_constructBSTRecursive(nums, left, mid - 1);
        node.right = bestSolution1_constructBSTRecursive(nums, mid + 1, right);
        return node;
    }

    // Best Solution 2: Recursion
    public TreeNode bestSolution2(int[] nums)
    {
        return nums.Length == 0
            ? null
            : new TreeNode(nums[nums.Length / 2],
                bestSolution2(nums.Take(nums.Length / 2).ToArray()),
                bestSolution2(nums.Skip(nums.Length / 2 + 1).ToArray())
            );
    }

    // Best Solution 3: Recursion
    public TreeNode bestSolution3(int[] nums)
    {
        double total = nums.Count();
        if (total == 0)
        {
            return null;
        }
        int mid = (int)Math.Floor(total / 2);
        int[] left = new int[mid];
        Array.Copy(nums, left, mid);
        int[] right = new int[nums.Length - mid - 1];
        Array.Copy(nums, mid + 1, right, 0, nums.Length - mid - 1);
        return new TreeNode(nums[mid], bestSolution3(left), bestSolution3(right));
    }
}
