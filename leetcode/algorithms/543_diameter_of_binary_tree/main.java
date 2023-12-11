import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

class DiameterOfBinaryTree {
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

    int result = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        getMaxNode(root);
        return result;
    }

    public int getMaxNode(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int left = getMaxNode(node.left);
        int right = getMaxNode(node.right);

        result = Math.max(result, left + right);

        return Math.max(left, right) + 1;
    }


    // Worst Solution
    public int worstSolution(TreeNode root) {
        if (root == null) {
            return 0;
        }
        HashMap<BigInteger[], TreeNode> treeMap = new HashMap<BigInteger[], TreeNode>();
        treeMap.put(new BigInteger[] { BigInteger.ZERO, BigInteger.ZERO }, root);
        int maxY = 0;
        int maxDistance = 0;
        boolean going = true;
        ArrayList<BigInteger> topSet = new ArrayList<BigInteger>();
        ArrayList<BigInteger[]> finalSet = new ArrayList<BigInteger[]>();
        while (going) {
            going = false;
            ArrayList<BigInteger> newTopSet = new ArrayList<BigInteger>();
            Iterator<BigInteger[]> itrKeys = treeMap.keySet().iterator();
            HashMap<BigInteger[], TreeNode> newTreeMap = new HashMap<BigInteger[], TreeNode>();
            while (itrKeys.hasNext()) {
                BigInteger[] coord = itrKeys.next();
                TreeNode nd = treeMap.get(coord);
                if (nd.left != null || nd.right != null) {
                    going = true;
                    BigInteger base = coord[0].multiply(BigInteger.valueOf(2L));
                    if (nd.left == null) {
                        newTreeMap.put(new BigInteger[] { base.add(BigInteger.ONE), coord[1].add(BigInteger.ONE) },
                                nd.right);
                        newTopSet.add(base.add(BigInteger.ONE));
                    } else {
                        newTreeMap.put(new BigInteger[] { base.subtract(BigInteger.ONE), coord[1].add(BigInteger.ONE) },
                                nd.left);
                        newTopSet.add(base.subtract(BigInteger.ONE));
                        if (nd.right != null) {
                            newTreeMap.put(new BigInteger[] { base.add(BigInteger.ONE), coord[1].add(BigInteger.ONE) },
                                    nd.right);
                        }
                    }
                } else {

                    finalSet.add(coord);
                }
            }

            if (going) {
                treeMap = newTreeMap;
                maxY++;
                topSet = newTopSet;

            }
        }
        finalSet.add(new BigInteger[] { BigInteger.ZERO, BigInteger.ZERO });
        for (BigInteger xTop : topSet) {
            System.out.println(xTop);
            for (BigInteger[] loc : finalSet) {
                BigInteger power = loc[0];
                for (int j = 0; j < maxY - loc[1].intValue(); j++) {
                    power = power.multiply(new BigInteger("2"));
                }
                BigInteger xLeft = power;
                BigInteger xRight = power;
                int twos = 0;
                int dist = 0;
                if (xTop.compareTo(xLeft) < 0) {
                    xLeft = xTop;
                }
                if (xTop.compareTo(xRight) > 0) {
                    xRight = xTop;
                }

                for (double i = xLeft.doubleValue(); i < xRight.doubleValue() + 1; i += 0) {
                    BigDecimal testD = new BigDecimal(i);
                    BigInteger test = testD.toBigInteger();
                    twos = 0;
                    BigInteger compare = test.mod(new BigInteger("2"));
                    while (compare.equals(new BigInteger("0"))) {
                        if (test.equals(BigInteger.ZERO)) {
                            twos = maxY;
                            break;

                        }
                        twos++;
                        test = test.divide(new BigInteger("2"));
                        compare = test.mod(new BigInteger("2"));
                    }
                    i += Math.pow(2, twos);
                    dist = twos * 2 - maxY + loc[1].intValue();
                    if (dist > maxDistance) {
                        maxDistance = dist;
                    }
                }
            }
        }
        return maxDistance;
    }


    // Best Solution
    // best solution 1
    int max = 0;

    public int bestSolution1(TreeNode root) {
        maxDepth(root);
        return max;
    }

    private int maxDepth(TreeNode root) {
        if (root == null)
            return 0;

        int left = maxDepth(root.left);
        int right = maxDepth(root.right);

        max = Math.max(max, left + right);

        return Math.max(left, right) + 1;
    }

    // best solution 2
    public int bestSolution2(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int dia = depth(root.left) + depth(root.right);
        int ldia = diameterOfBinaryTree(root.left);
        int rdia = diameterOfBinaryTree(root.right);
        return Math.max(dia, Math.max(ldia, rdia));
    }

    public int depth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + Math.max(depth(root.left), depth(root.right));
    }
}