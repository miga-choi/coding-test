import java.util.TreeSet;

class MinimumAbsoluteDifferenceInBST {
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

    int min = Double.valueOf(Math.pow(10, 5)).intValue();
    int prevValue = -1;

    public int getMinimumDifference(TreeNode root) {
        if (root == null) {
            return min;
        }

        getMinimumDifference(root.left);

        if (prevValue >= 0) {
            min = Math.min(min, Math.abs(prevValue - root.val));
        }
        prevValue = root.val;

        getMinimumDifference(root.right);

        return min;
    }


    // Best Solution
    // In-Order traverse
    int bestSolution1Min = Integer.MAX_VALUE;
    Integer bestSolution1Prev = null;

    public int bestSolution1(TreeNode root) {
        if (root == null) {
            return bestSolution1Min;
        }

        bestSolution1(root.left);

        if (bestSolution1Prev != null) {
            bestSolution1Min = Math.min(bestSolution1Min, root.val - bestSolution1Prev);
        }
        bestSolution1Prev = root.val;

        bestSolution1(root.right);

        return bestSolution1Min;
    }

    // Pre-Order traverse
    TreeSet<Integer> bestSolution2Set = new TreeSet<Integer>();
    int bestSolution2Min = Integer.MAX_VALUE;

    public int bestSolution2(TreeNode root) {
        if (root == null) {
            return bestSolution2Min;
        }

        if (!bestSolution2Set.isEmpty()) {
            if (bestSolution2Set.floor(root.val) != null) {
                bestSolution2Min = Math.min(bestSolution2Min, root.val - bestSolution2Set.floor(root.val));
            }
            if (bestSolution2Set.ceiling(root.val) != null) {
                bestSolution2Min = Math.min(bestSolution2Min, bestSolution2Set.ceiling(root.val) - root.val);
            }
        }

        bestSolution2Set.add(root.val);

        bestSolution2(root.left);
        bestSolution2(root.right);

        return bestSolution2Min;
    }
}