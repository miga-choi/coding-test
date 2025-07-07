import java.util.ArrayList;
import java.util.List;

class MinimumDistanceBetweenBSTNodes {
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

    private void inorderTraversal(TreeNode node, List<Integer> vals) {
        if (node == null) {
            return;
        }

        inorderTraversal(node.left, vals);
        vals.add(node.val);
        inorderTraversal(node.right, vals);
    }

    public int minDiffInBST(TreeNode root) {
        List<Integer> vals = new ArrayList<Integer>();

        inorderTraversal(root, vals);

        int min = 100000;

        for (int i = 0; i < vals.size() - 1; i++) {
            int diff = vals.get(i + 1) - vals.get(i);
            if (diff < min) {
                min = diff;
            }
        }

        return min;
    }


    // Solution
    Integer res = Integer.MAX_VALUE, pre = null;

    public int solution(TreeNode root) {
        if (root.left != null) {
            minDiffInBST(root.left);
        }

        if (pre != null) {
            res = Math.min(res, root.val - pre);
        }

        pre = root.val;

        if (root.right != null) {
            minDiffInBST(root.right);
        }

        return res;
    }
}
