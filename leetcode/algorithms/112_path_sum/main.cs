using System.gene
public class PathSum
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

    public bool HasPathSum(TreeNode root, int targetSum)
    {
        if (root == null)
        {
            return false;
        }
        if (root.left == null)
        {
            return getSum(targetSum, root.right, root.val);
        }
        if (root.right == null)
        {
            return getSum(targetSum, root.left, root.val);
        }
        return getSum(targetSum, root.left, root.val) || getSum(targetSum, root.right, root.val);
    }

    public bool getSum(int targetSum, TreeNode node, int sum)
    {
        if (node == null)
        {
            return targetSum == sum;
        }
        sum += node.val;
        if (node.left == null)
        {
            return getSum(targetSum, node.right, sum);
        }
        if (node.right == null)
        {
            return getSum(targetSum, node.left, sum);
        }
        return getSum(targetSum, node.left, sum) || getSum(targetSum, node.right, sum);
    }


    // Best Solution
    // Best Solution 1:
    public bool bestSolution1(TreeNode root, int targetSum)
    {
        if (root == null)
        {
            return false;
        }

        if (root.left == null && root.right == null)
        {
            return targetSum == root.val;
        }

        bool leftSum = bestSolution1(root.left, targetSum - root.val);
        bool rightSum = bestSolution1(root.right, targetSum - root.val);

        return leftSum || rightSum;
    }

    // Best Solution 2:
    public bool bestSolution2(TreeNode root, int targetSum)
    {
        if (root == null)
        {
            return false;
        }

        // minus value of current node
        targetSum -= root.val;

        // check if now a leaf node
        if (root.left == null && root.right == null)
        {
            return targetSum == 0;
        }

        return bestSolution2(root.left, targetSum) || bestSolution2(root.right, targetSum);
    }

    // Best Solution 3: Iterator (Depth-First Search) with stack 
    public bool bestSolution3(TreeNode root, int targetSum)
    {
        if (root == null)
        {
            return false;
        }

        var stack = new Stack<(TreeNode Node, int Sum)>();
        stack.Push((root, root.val));
        while (stack.Count != 0)
        {
            var p = stack.Pop();
            TreeNode node = p.Node;
            int psum = p.Sum;

            if (node.right != null)
            {
                stack.Push((node.right, node.right.val + psum));
            }
            if (node.left != null)
            {
                stack.Push((node.left, node.left.val + psum));
            }

            if (node.left == null && node.right == null && psum == targetSum)
            {
                return true;
            }
        }
        return false;
    }
}
