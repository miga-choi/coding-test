import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class SameTree {
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

  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null) {
      return true;
    }
    if (p == null && q != null) {
      return false;
    }
    if (p != null && q == null) {
      return false;
    }
    if (p.val != q.val) {
      return false;
    }
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
  }


  // Best Solution
  // Best Solution 1: Recursive (DFS) Preorder traversal
  public boolean bestSolution1(TreeNode p, TreeNode q) {
    // Base case: If both trees are empty, they are identical.
    if (p == null && q == null) {
      return true;
    }
    // If one of the trees is empty and the other is not, they are not identical.
    if (p == null || q == null) {
      return false;
    }

    // Compare the values of the current nodes.
    if (p.val != q.val) {
      return false;
    }

    // Recursively check the left and right subtrees.
    return bestSolution1(p.left, q.left) && bestSolution1(p.right, q.right);
  }

  // Best Solution 2: Level-order traversal using Queues
  public boolean bestSolution2(TreeNode p, TreeNode q) {
    // Create queues for both trees.
    Queue<TreeNode> queue1 = new LinkedList<>();
    Queue<TreeNode> queue2 = new LinkedList<>();

    // Start by adding the root nodes of both trees to their respective queues.
    queue1.offer(p);
    queue2.offer(q);

    while (!queue1.isEmpty() && !queue2.isEmpty()) {
      TreeNode node1 = queue1.poll();
      TreeNode node2 = queue2.poll();

      // If the values of the current nodes are not equal, the trees are not
      // identical.
      if (node1 == null && node2 == null) {
        continue;
      }
      if (node1 == null || node2 == null || node1.val != node2.val) {
        return false;
      }

      // Add the left and right children of both nodes to their respective queues.
      queue1.offer(node1.left);
      queue1.offer(node1.right);
      queue2.offer(node2.left);
      queue2.offer(node2.right);
    }

    // If both queues are empty, the trees are identical.
    return queue1.isEmpty() && queue2.isEmpty();
  }

  // Best Solution 3: Level-order traversal using Stack
  public boolean bestSolution3(TreeNode p, TreeNode q) {
    Stack<TreeNode> stack1 = new Stack<>();
    Stack<TreeNode> stack2 = new Stack<>();

    // Push the root nodes of both trees onto their respective stacks.
    stack1.push(p);
    stack2.push(q);

    while (!stack1.isEmpty() && !stack2.isEmpty()) {
      TreeNode node1 = stack1.pop();
      TreeNode node2 = stack2.pop();

      // Compare the values of the current nodes.
      if (node1 == null && node2 == null) {
        // Both nodes are null, so they match.
        continue;
      } else if (node1 == null || node2 == null || node1.val != node2.val) {
        // Nodes are not identical, return false.
        return false;
      }

      // Push the left children onto the stacks.
      stack1.push(node1.left);
      stack2.push(node2.left);

      // Push the right children onto the stacks.
      stack1.push(node1.right);
      stack2.push(node2.right);
    }

    // If both stacks are empty, and no mismatches have been found, the trees are
    // identical.
    return stack1.isEmpty() && stack2.isEmpty();
  }

  // Best Solution 4: Tree Hashing
  public boolean bestSolution4(TreeNode p, TreeNode q) {
    String hash1 = bestSolution4_computeTreeHash(p);
    String hash2 = bestSolution4_computeTreeHash(q);
    return hash1.equals(hash2);
  }

  private String bestSolution4_computeTreeHash(TreeNode node) {
    if (node == null) {
      return "null";
    }
    String leftHash = bestSolution4_computeTreeHash(node.left);
    String rightHash = bestSolution4_computeTreeHash(node.right);
    return "(" + node.val + leftHash + rightHash + ")";
  }
}
