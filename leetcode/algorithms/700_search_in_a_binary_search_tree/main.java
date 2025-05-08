class SearchInABinarySearchTree {
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

    public TreeNode searchBST(TreeNode root, int val) {
        if (root != null) {
            if (root.val == val) {
                return root;
            }

            TreeNode left = searchBST(root.left, val);
            if (left != null) {
                return left;
            }

            TreeNode right = searchBST(root.right, val);
            if (right != null) {
                return right;
            }
        }

        return null;
    }


    // Solution
    // Solution 1: Recursion
    public TreeNode solution1(TreeNode root, int val) {
        if (root == null) {
            return root;
        }

        if (root.val == val) {
            return root;
        }

        return root.val > val ? solution1(root.left, val) : solution1(root.right, val);
    }

    // Solution 2: Iteration
    public TreeNode solution2(TreeNode root, int val) {
        while (root != null && root.val != val) {
            root = root.val > val ? solution2(root.left, val) : solution2(root.right, val);
        }
        return root;
    }
}
