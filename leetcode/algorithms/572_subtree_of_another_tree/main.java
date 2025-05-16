class SubtreeOfAnotherTree {
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

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
        return compareNode(root, subRoot)
                || isSubtree(root.left, subRoot)
                || isSubtree(root.right, subRoot);
    }

    public boolean compareNode(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) {
            return true;
        } else if (node1 == null || node2 == null) {
            return false;
        } else {
            return node1.val == node2.val
                    && compareNode(node1.left, node2.left)
                    && compareNode(node1.right, node2.right);
        }
    }


    // Solution
    // Solution 1: Naive
    public boolean solution1(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
        if (isSame(root, subRoot)) {
            return true;
        }
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }

    private boolean isSame(TreeNode root, TreeNode subRoot) {
        if (root == null && subRoot == null) {
            return true;
        }
        if (root == null || subRoot == null) {
            return false;
        }

        if (root.val != subRoot.val) {
            return false;
        }

        return isSame(root.left, subRoot.left) && isSame(root.right, subRoot.right);
    }

    // Solution 2: Serialize in Preorder then KMP
    public boolean solution2(TreeNode root, TreeNode subRoot) {
        return kmp(serialize(root), serialize(subRoot));
    }

    boolean kmp(String s, String p) { // Check if s contains p?
        int[] lps = getLPS(p);
        int n = s.length(), m = p.length();
        for (int i = 0, j = 0; i < n; ++i) {
            while (s.charAt(i) != p.charAt(j) && j > 0)
                j = lps[j - 1];
            if (s.charAt(i) == p.charAt(j))
                j++;
            if (j == m)
                return true;
        }
        return false;
    }

    int[] getLPS(String p) {
        int m = p.length();
        int[] lps = new int[m];
        for (int i = 1, j = 0; i < m; ++i) {
            while (p.charAt(i) != p.charAt(j) && j > 0)
                j = lps[j - 1];
            if (p.charAt(i) == p.charAt(j))
                lps[i] = ++j;
        }
        return lps;
    }

    String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }

    void serialize(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append(",#");
        } else {
            sb.append("," + root.val);
            serialize(root.left, sb);
            serialize(root.right, sb);
        }
    }
}
