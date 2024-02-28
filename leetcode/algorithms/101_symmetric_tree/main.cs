using System.Collections.Generic;

public class SymmetricTree
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

    public bool IsSymmetric(TreeNode root)
    {
        if (root == null)
        {
            return true;
        }

        return CheckNode(root.left, root.right);
    }

    public bool CheckNode(TreeNode left, TreeNode right)
    {
        if (left == null && right == null)
        {
            return true;
        }

        if (left == null || right == null || left.val != right.val)
        {
            return false;
        }

        return CheckNode(left.left, right.right) && CheckNode(left.right, right.left);
    }


    // Best Solution
    // Best Solution 1: Recursive
    public bool bestSolution1(TreeNode root) => bestSolution1_CheckSymetry(root?.left, root?.right);

    private bool bestSolution1_CheckSymetry(TreeNode left, TreeNode right)
    {
        if (left == null || right == null)
        {
            return left?.val == right?.val;
        }

        if (left.val != right.val)
        {
            return false;
        }

        return bestSolution1_CheckSymetry(left.left, right.right) && bestSolution1_CheckSymetry(left.right, right.left);
    }

    // Best Solution 2: Iterative DFS
    public bool bestSolution2(TreeNode root)
    {
        if (root == null)
        {
            return true;
        }

        var stack = new Stack<(TreeNode, TreeNode)>();
        stack.Push((root.left, root.right));

        while (stack.Any())
        {
            switch (stack.Pop())
            {
                case (null, null):
                    continue;

                case (null, _) or (_, null):
                    return false;

                case (TreeNode l, TreeNode r) when l.val != r.val:
                    return false;

                case (TreeNode l, TreeNode r) when l.val == r.val:
                    stack.Push((l.left, r.right));
                    stack.Push((l.right, r.left));
                    break;
            }
        }

        return true;
    }
}
