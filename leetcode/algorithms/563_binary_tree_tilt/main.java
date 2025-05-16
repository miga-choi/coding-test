class BinaryTreeTilt {
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

    int result = 0;

    public int findTilt(TreeNode root) {
        getVal(root);
        return result;
    }

    private int getVal(TreeNode node) {
        if (node != null) {
            int left = getVal(node.left);
            int right = getVal(node.right);
            result += Math.abs(left - right);
            return left + right + node.val;
        } else {
            return 0;
        }
    }


    // Solution
    int solutionResult = 0;

    public int solution(TreeNode root) {
        postOrder(root);
        return solutionResult;
    }

    private int postOrder(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = postOrder(root.left);
        int right = postOrder(root.right);

        solutionResult += Math.abs(left - right);

        return left + right + root.val;
    }
}