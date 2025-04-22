import java.util.LinkedList;

class InvertBinaryTree {
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

    public TreeNode invertTree(TreeNode root) {
        if (root != null) {
            TreeNode tempNode = invertTree(root.left);
            root.left = invertTree(root.right);
            root.right = tempNode;
        }
        return root;
    }


    // Solution
    // Solution 1: Recursive Approach
    public TreeNode solution1(TreeNode root) {
        // Base case: if the tree is empty...
        if (root == null) {
            return root;
        }

        // Call the function recursively for the left subtree...
        solution1(root.left);

        // Call the function recursively for the right subtree...
        solution1(root.right);

        // Swapping process...
        TreeNode curr = root.left;
        root.left = root.right;
        root.right = curr;

        // Return the root...
        return root;
    }

    // Solution 2: Iterative Approach
    public TreeNode solution2(TreeNode root) {
        LinkedList<TreeNode> q = new LinkedList<TreeNode>();

        // Base case: if the tree is empty...
        if (root != null) {
            // Push the root node...
            q.add(root);
        }

        // Loop till queue is empty...
        while (!q.isEmpty()) {
            // Dequeue front node...
            TreeNode temp = q.poll();

            // Enqueue left child of the popped node...
            if (temp.left != null) {
                q.add(temp.left);
            }

            // Enqueue right child of the popped node
            if (temp.right != null) {
                q.add(temp.right);
            }

            // Swapping process...
            TreeNode curr = temp.left;
            temp.left = temp.right;
            temp.right = curr;
        }

        // Return the root...
        return root;
    }
}
