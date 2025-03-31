import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class TwoSum4InputIsABST {
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

    private void inorder(TreeNode node, List<Integer> valArray) {
        if (node != null) {
            inorder(node.left, valArray);
            valArray.add(node.val);
            inorder(node.right, valArray);
        }
    }

    public boolean findTarget(TreeNode root, int k) {
        List<Integer> valArray = new ArrayList<Integer>();

        inorder(root, valArray);

        int left = 0;
        int right = valArray.size() - 1;

        while (left < right) {
            int sum = valArray.get(left) + valArray.get(right);
            if (sum < k) {
                left++;
            } else if (sum > k) {
                right--;
            } else {
                return true;
            }
        }

        return false;
    }

    // Solution
    public boolean dfs(TreeNode root, HashSet<Integer> set, int k) {
        if (root == null) {
            return false;
        }
        if (set.contains(k - root.val)) {
            return true;
        }
        set.add(root.val);
        return dfs(root.left, set, k) || dfs(root.right, set, k);
    }

    public boolean solution(TreeNode root, int k) {
        HashSet<Integer> set = new HashSet<Integer>();
        return dfs(root, set, k);
    }
}
