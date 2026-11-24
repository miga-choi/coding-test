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

    /**
     * In-order Traversal to Array + Two-Pass Run Counting
     *
     * Complexities:
     *   n - The Number of Nodes in `root`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(n)
     */
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> result = new ArrayList<>();

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
    /**
     * Solution 1
     *
     * In-order Traversal (Streaming Count)
     *
     * Complexities:
     *   n - The Number of Nodes in `root`
     *   h - The Height of `root`
     *   m - The Size of returned `int[]`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(h + m)
     */
    private Integer prev1 = null;
    private int count1 = 0, maxCount1 = 0;
    private final List<Integer> modes1 = new ArrayList<>();

    public int[] solution1(TreeNode root) {
        inorder1(root);

        int[] result = new int[modes1.size()];

        for (int i = 0; i < result.length; i++) {
            result[i] = modes1.get(i);
        }

        return result;
    }

    private void inorder1(TreeNode node) {
        if (node == null) {
            return;
        }

        inorder1(node.left);

        if (prev1 != null && prev1 == node.val) {
            count1++;
        } else {
            count1 = 1;
        }

        prev1 = node.val;

        if (count1 > maxCount1) {
            maxCount1 = count1;
            modes1.clear();
            modes1.add(node.val);
        } else if (count1 == maxCount1) {
            modes1.add(node.val);
        }

        inorder1(node.right);
    }

    /**
     * Solution 2
     *
     * Two-Pass In-order Traversal
     *
     * Complexities:
     *   n - The Number of Nodes in `root`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    private int prev2, count2, maxCount2, modeCount2;
    private int[] modes2;

    public int[] solution2(TreeNode root) {
        inorder(root);

        modes2 = new int[modeCount2];
        count2 = 0;
        modeCount2 = 0;
        inorder(root);

        return modes2;
    }

    private void inorder(TreeNode node) {
        if (node == null) {
            return;
        }

        inorder(node.left);
        handle2(node.val);
        inorder(node.right);
    }

    private void handle2(int val) {
        if (count2 == 0 || val != prev2) {
            count2 = 1;
            prev2 = val;
        } else {
            count2++;
        }

        if (count2 > maxCount2) {
            maxCount2 = count2;
            modeCount2 = 1;

            if (modes2 != null) {
                modes2[0] = val;
            }
        } else if (count2 == maxCount2) {
            if (modes2 != null) {
                modes2[modeCount2] = val;
            }

            modeCount2++;
        }
    }

    /**
     * Solution 3
     *
     * Morris Traversal
     *
     * Complexities:
     *   n - The Number of Nodes in `root`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    private int prev3, count3, maxCount3, modeCount3;
    private int[] modes3;

    public int[] solution3(TreeNode root) {
        morris(root);

        modes3 = new int[modeCount3];
        count3 = 0;
        modeCount3 = 0;
        morris(root);

        return modes3;
    }

    private void handle3(int val) {
        if (count3 == 0 || val != prev3) {
            count3 = 1;
            prev3 = val;
        } else {
            count3++;
        }

        if (count3 > maxCount3) {
            maxCount3 = count3;
            modeCount3 = 1;

            if (modes3 != null) {
                modes3[0] = val;
            }
        } else if (count3 == maxCount3) {
            if (modes3 != null) {
                modes3[modeCount3] = val;
            }

            modeCount3++;
        }
    }

    private void morris(TreeNode root) {
        TreeNode cur = root;

        while (cur != null) {
            if (cur.left == null) {
                handle3(cur.val);
                cur = cur.right;
            } else {
                TreeNode pred = cur.left;

                while (pred.right != null && pred.right != cur) {
                    pred = pred.right;
                }

                if (pred.right == null) {
                    pred.right = cur;
                    cur = cur.left;
                } else {
                    pred.right = null;
                    handle3(cur.val);
                    cur = cur.right;
                }
            }
        }
    }
}
