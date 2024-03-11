using System;

public class MinimumDepthOfBinaryTree
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

    public int MinDepth(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }

        int left = MinDepth(root.left);
        int right = MinDepth(root.right);

        if (left == 0 && right == 0)
        {
            return 1;
        }
        else if (left == 0)
        {
            return right + 1;
        }
        else if (right == 0)
        {
            return left + 1;
        }

        return Math.Min(left, right) + 1;
    }


    // Best Solution
    // Best Solution 1: DFS (Depth-First Search)
    public int bestSolution1(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }

        var leftMinDepth = MinDepth(root.left);
        var rightMinDepth = MinDepth(root.right);

        if (leftMinDepth == 0 || rightMinDepth == 0)
        {
            return Math.Max(leftMinDepth, rightMinDepth) + 1;
        }

        return Math.Min(leftMinDepth, rightMinDepth) + 1;
    }

    // Best Solution 2: BFS (Breadth-First Search)
    public int bestSolution2(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }

        var queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        var depth = 0;

        while (queue.Count != 0)
        {
            var size = queue.Count;

            for (var i = 0; i < size; i++)
            {
                var current = queue.Dequeue();

                if (current.left != null)
                {
                    queue.Enqueue(current.left);
                }

                if (current.right != null)
                {
                    queue.Enqueue(current.right);
                }

                if (current.left == null && current.right == null)
                {
                    return depth + 1;
                }
            }

            depth++;
        }

        return 0;
    }
}
