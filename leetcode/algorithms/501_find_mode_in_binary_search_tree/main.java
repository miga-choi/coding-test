import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class FindModeInBinarySearchTree {
    /**
     * Definition for a binary tree node.
     */
    class TreeNode {
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

    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        List<Integer> result = new ArrayList<Integer>();

        checkNode(map, root);

        System.out.println();
        int max = Collections.max(map.values());

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() >= max) {
                result.add(entry.getKey());
            }
        }

        return result.stream().mapToInt(v -> v).toArray();
    }

    public void checkNode(Map<Integer, Integer> map, TreeNode node) {
        if (node == null) {
            return;
        }

        if (node.left != null) {
            checkNode(map, node.left);
        }

        if (node.right != null) {
            checkNode(map, node.right);
        }

        if (map.get(node.val) == null) {
            map.put(node.val, 1);
        } else {
            map.put(node.val, map.get(node.val) + 1);
        }
    }


    // Solution
    // Solution 1: In-order traversal
    private int currVal;
    private int currCount = 0;
    private int maxCount = 0;
    private int modeCount = 0;

    private int[] modes;

    private void handleValue(int val) {
        if (val != currVal) {
            currVal = val;
            currCount = 0;
        }
        currCount++;
        if (currCount > maxCount) {
            maxCount = currCount;
            modeCount = 1;
        } else if (currCount == maxCount) {
            if (modes != null) {
                modes[modeCount] = currVal;
            }
            modeCount++;
        }
    }

    public int[] solution1(TreeNode root) {
        inorder(root);
        modes = new int[modeCount];
        modeCount = 0;
        currCount = 0;
        inorder(root);
        return modes;
    }

    private void inorder(TreeNode root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        handleValue(root.val);
        inorder(root.right);
    }

    // Solution 2: Morris traversal
    public int[] solution2(TreeNode root) {
        morris(root);
        modes = new int[modeCount];
        modeCount = 0;
        currCount = 0;
        morris(root);
        return modes;
    }

    private void morris(TreeNode root) {
        TreeNode node = root;
        while (node != null) {
            if (node.left == null) {
                handleValue(node.val);
                node = node.right;
            } else {
                TreeNode prev = node.left;
                while (prev.right != null && prev.right != node) {
                    prev = prev.right;
                }
                if (prev.right == null) {
                    prev.right = node;
                    node = node.left;
                } else {
                    prev.right = null;
                    handleValue(node.val);
                    node = node.right;
                }
            }
        }
    }
}
