import java.util.ArrayList;
import java.util.List;

class BinaryTreePaths {
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

    /**
     * DFS + Backtracking
     *
     * Complexities:
     *   N - The number of nodes in `root`
     *   H - The height of tree in `root`
     *   - Time Complexity: O(N * H)
     *   - Space Complexity: O(H)
     */
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<>();

        if (root == null) {
            return result;
        }

        if (root.left == null && root.right == null) {
            result.add(String.valueOf(root.val));
            return result;
        }

        List<String> leftArray = binaryTreePaths(root.left);
        List<String> rightArray = binaryTreePaths(root.right);

        String left = "";
        String right = "";

        for (String left_ : leftArray) {
            left = String.valueOf(root.val) + "->" + left_;
            result.add(left);
        }

        for (String right_ : rightArray) {
            right = String.valueOf(root.val) + "->" + right_;
            result.add(right);
        }

        return result;
    }


    // Solution
    /**
     * DFS + Backtracking
     *
     * Complexities:
     *   N - The number of nodes in `root`
     *   H - The height of tree in `root`
     *   - Time Complexity: O(N * H)
     *   - Space Complexity: O(H)
     */
    public List<String> solution(TreeNode root) {
        List<String> result = new ArrayList<>();

        if (root != null) {
            dfs(root, "", result);
        }

        return result;
    }

    private void dfs(TreeNode node, String path, List<String> result) {
        if (node.left == null && node.right == null) {
            result.add(path + node.val);
            return;
        }

        if (node.left != null) {
            dfs(node.left, path + node.val + "->", result);
        }

        if (node.right != null) {
            dfs(node.right, path + node.val + "->", result);
        }
    }
}
