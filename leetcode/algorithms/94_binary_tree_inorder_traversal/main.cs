using System.Collections.Generic;

public class BinaryTreeInorderTraversal {
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

    public void getVal(TreeNode node, List<int> array) {
        if (node != null) {
            getVal(node.left, array);
            array.Add(node.val);
            getVal(node.right, array);
        }
    }

    public IList<int> InorderTraversal(TreeNode root) {
        List<int> result = new List<int>();
        getVal(root, result);
        return result;
    }


    // Solution
    // Solution 1:
    List<int> ans = new List<int>();

    public IList<int> solution1(TreeNode root) {
        if (root == null) {
            return ans;
        }
        solution1(root.left);
        ans.Add(root.val);
        solution1(root.right);
        return ans;
    }

    // Solution 2: Iterative with stack
    public IList<int> solution2(TreeNode root) {
        List<int> result = new List<int>();
        Stack<TreeNode> stack = new Stack<TreeNode>();

        while (root != null || stack.Count > 0) {
            while (root != null) {
                stack.Push(root);
                root = root.left;
            }
            root = stack.Pop();
            result.Add(root.val);
            root = root.right;
        }

        return result;
    }

    // Solution 3: Morris traversal
    public IList<int> solution3(TreeNode root) {
        List<int> result = new List<int>();
        TreeNode current = root;

        while (current != null) {
            if (current.left == null) {
                result.Add(current.val);
                current = current.right;
            } else {
                TreeNode predecessor = current.left;

                while (predecessor.right != null && predecessor.right != current) {
                    predecessor = predecessor.right;
                }

                if (predecessor.right == null) {
                    predecessor.right = current;
                    current = current.left;
                } else {
                    predecessor.right = null;
                    result.Add(current.val);
                    current = current.right;
                }
            }
        }

        return result;
    }
}
