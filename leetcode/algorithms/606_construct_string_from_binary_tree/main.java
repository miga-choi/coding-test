class ConstructStringFromBinaryTree {
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

    public String tree2str(TreeNode root) {
        if (root == null) {
            return "";
        }

        if (root.left == null && root.right == null) {
            return String.valueOf(root.val);
        }
        String left = "()";
        if (root.left != null) {
            left = "(" + tree2str(root.left) + ")";
        }

        String right = "";
        if (root.right != null) {
            right = "(" + tree2str(root.right) + ")";
        }

        return String.valueOf(root.val) + left + right;
    }


    // Solution
    public String solution(TreeNode root) {
        return "";
    }
}
