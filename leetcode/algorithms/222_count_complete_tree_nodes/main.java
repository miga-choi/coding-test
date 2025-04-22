class CountCompleteTreeNodes {
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

    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return countNodes(root.left) + countNodes(root.right) + 1;
    }


    // Solution
    int height(TreeNode root) {
        return root == null ? -1 : 1 + height(root.left);
    }

    public int solution(TreeNode root) {
        int h = height(root);
        return h < 0 ? 0
                : (height(root.right) == h - 1 ? (1 << h) + countNodes(root.right)
                        : (1 << h - 1) + countNodes(root.left));
    }
}
