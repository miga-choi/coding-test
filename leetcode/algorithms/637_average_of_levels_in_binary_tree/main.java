import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class AverageOfLevelsInBinaryTree {
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

    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<Double>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();

        queue.add(root);
        while (!queue.isEmpty()) {
            int nodeCount = queue.size();
            Double sum = 0.0;
            for (int i = 0; i < nodeCount; i++) {
                TreeNode node = queue.poll();
                sum += node.val;
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            result.add(sum / nodeCount);
        }

        return result;
    }

    // Solution
    public List<Double> solution(TreeNode root) {
        List<Double> result = new ArrayList<Double>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();

        if (root == null) {
            return result;
        }

        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            double sum = 0.0;
            for (int i = 0; i < n; i++) {
                TreeNode node = q.poll();
                sum += node.val;
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
            result.add(sum / n);
        }

        return result;
    }
}
