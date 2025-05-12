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


    // Solution
    // Solution 1: In-Order traverse
    int solution1Min = Integer.MAX_VALUE;
    Integer solution1Prev = null;

    public int solution1(TreeNode root) {
        if (root == null) {
            return solution1Min;
        }

        solution1(root.left);

        if (solution1Prev != null) {
            solution1Min = Math.min(solution1Min, root.val - solution1Prev);
        }
        solution1Prev = root.val;

        solution1(root.right);

        return solution1Min;
    }

    // Solution 2: Pre-Order traverse
    TreeSet<Integer> solution2Set = new TreeSet<Integer>();
    int solution2Min = Integer.MAX_VALUE;

    public int solution2(TreeNode root) {
        if (root == null) {
            return solution2Min;
        }

        if (!solution2Set.isEmpty()) {
            if (solution2Set.floor(root.val) != null) {
                solution2Min = Math.min(solution2Min, root.val - solution2Set.floor(root.val));
            }
            if (solution2Set.ceiling(root.val) != null) {
                solution2Min = Math.min(solution2Min, solution2Set.ceiling(root.val) - root.val);
            }
        }

        solution2Set.add(root.val);

        solution2(root.left);
        solution2(root.right);

        return solution2Min;
    }
}
