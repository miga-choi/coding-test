using System.Collections.Generic;

public class SameTree {
    public class TreeNode {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public bool IsSameTree(TreeNode p, TreeNode q) {
        return checkNode(p, q);
    }

    public bool checkNode(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) {
            return true;
        }

        if (node1 == null || node2 == null || node1.val != node2.val) {
            return false;
        }

        return checkNode(node1.left, node2.left) && checkNode(node1.right, node2.right);
    }


    //  Solution
    //  Solution 1: Recursive (DFS) Preorder traversal
    public bool solution1(TreeNode p, TreeNode q) {
        // Base case: If both trees are empty, they are identical.
        if (p == null && q == null) {
            return true;
        }

        // If one of the trees is empty and the other is not, they are not identical.
        if (p == null || q == null) {
            return false;
        }

        // Compare the values of the current nodes.
        if (p.val != q.val) {
            return false;
        }

        // Recursively check the left and right subtrees.
        return solution1(p.left, q.left) && solution1(p.right, q.right);
    }

    //  Solution 2: Level-order traversal using Queues
    public bool solution2(TreeNode p, TreeNode q) {
        // Create queues for both trees.
        Queue<TreeNode> queue1 = new Queue<TreeNode>();
        Queue<TreeNode> queue2 = new Queue<TreeNode>();

        // Start by adding the root nodes of both trees to their respective queues.
        queue1.Enqueue(p);
        queue2.Enqueue(q);

        while (queue1.Count > 0 && queue2.Count > 0) {
            TreeNode node1 = queue1.Dequeue();
            TreeNode node2 = queue2.Dequeue();

            // If the values of the current nodes are not equal, the trees are not identical.
            if (node1 == null && node2 == null) {
                continue;
            }
            if (node1 == null || node2 == null || node1.val != node2.val) {
                return false;
            }

            // Add the left and right children of both nodes to their respective queues.
            queue1.Enqueue(node1.left);
            queue1.Enqueue(node1.right);
            queue2.Enqueue(node2.left);
            queue2.Enqueue(node2.right);
        }

        // If both queues are empty, the trees are identical.
        return queue1.Count == 0 && queue2.Count == 0;
    }

    //  Solution 3: Level-order traversal using Stack
    public bool solution3(TreeNode p, TreeNode q) {
        Stack<TreeNode> stack1 = new Stack<TreeNode>();
        Stack<TreeNode> stack2 = new Stack<TreeNode>();

        stack1.Push(p);
        stack2.Push(q);

        while (stack1.Count > 0 && stack2.Count > 0) {
            TreeNode node1 = stack1.Pop();
            TreeNode node2 = stack2.Pop();

            if (node1 == null && node2 == null) {
                continue;
            } else if (node1 == null || node2 == null || node1.val != node2.val) {
                return false;
            }

            stack1.Push(node1.left);
            stack2.Push(node2.left);
            stack1.Push(node1.right);
            stack2.Push(node2.right);
        }

        return stack1.Count == 0 && stack2.Count == 0;
    }

    //  Solution 4: Tree Hashing
    public bool solution4(TreeNode p, TreeNode q)
    {
        string hash1 = solution4_computeTreeHash(p);
        string hash2 = solution4_computeTreeHash(q);
        return hash1.Equals(hash2);
    }

    private string solution4_computeTreeHash(TreeNode node) {
        if (node == null) {
            return "null";
        }
        string leftHash = solution4_computeTreeHash(node.left);
        string rightHash = solution4_computeTreeHash(node.right);
        return $"({node.val}{leftHash}{rightHash})";
    }
}
