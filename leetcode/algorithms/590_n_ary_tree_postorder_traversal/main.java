import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

class NAryTreePostorderTraversal {
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

    public List<Integer> postorder(Node root) {
        return traversal(root, new ArrayList<Integer>());
    }

    List<Integer> traversal(Node node, List<Integer> list) {
        if (node != null) {
            for (Node child : node.children) {
                traversal(child, list);
            }
            list.add(node.val);
        }
        return list;
    }


    // Solution
    // Solution 1: Iterative
    public List<Integer> solution1(Node root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) {
            return list;
        }

        Stack<Node> stack = new Stack<>();
        stack.add(root);

        while (!stack.isEmpty()) {
            root = stack.pop();
            list.add(root.val);
            for (Node node : root.children) {
                stack.add(node);
            }
        }

        Collections.reverse(list);

        return list;
    }

    // Solution 2: Recursive
    List<Integer> list = new ArrayList<>();

    public List<Integer> solution2(Node root) {
        if (root == null) {
            return list;
        }

        for (Node node : root.children) {
            postorder(node);
        }

        list.add(root.val);

        return list;
    }
}
