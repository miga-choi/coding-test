import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class MaximumDepthOfNAryTree {
  class Node {
    public int val;
    public List<Node> children;

    public Node() {
    }

    public Node(int _val) {
      val = _val;
    }

    public Node(int _val, List<Node> _children) {
      val = _val;
      children = _children;
    }
  }

  public int maxDepth(Node root) {
    if (root == null) {
      return 0;
    }
    int max = 0;
    for (Node child : root.children) {
      max = Math.max(max, maxDepth(child));
    }
    return max + 1;
  }


  // Solution
  public int solution(Node root) {
    if (root == null) {
      return 0;
    }

    Queue<Node> queue = new LinkedList<>();
    queue.offer(root);

    int depth = 0;

    while (!queue.isEmpty()) {
      int size = queue.size();

      for (int i = 0; i < size; i++) {
        Node current = queue.poll();
        for (Node child : current.children) {
          queue.offer(child);
        }
      }

      depth++;
    }

    return depth;
  }
}
