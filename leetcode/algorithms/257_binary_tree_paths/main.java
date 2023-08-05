
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

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

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<String>();

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


    // Best Solution
    public List<String> bestSolution(TreeNode root) {
        List<String> answer = new ArrayList<String>();
        if (root != null) {
            searchBT(root, "", answer);
        }
        return answer;
    }

    private void searchBT(TreeNode root, String path, List<String> answer) {
        if (root.left == null && root.right == null) {
            answer.add(path + root.val);
        }
        if (root.left != null) {
            searchBT(root.left, path + root.val + "->", answer);
        }
        if (root.right != null) {
            searchBT(root.right, path + root.val + "->", answer);
        }
    }
}