import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class NAryTreePreorderTraversal {
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
    };

    public List<Integer> preorder(Node root) {
        return getVal(root, new ArrayList<Integer>());
    }

    List<Integer> getVal(Node node, List<Integer> list) {
        if (node != null) {
            list.add(node.val);
            for (Node child : node.children) {
                getVal(child, list);
            }
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

        while (!stack.empty()) {
            root = stack.pop();
            list.add(root.val);
            for (int i = root.children.size() - 1; i >= 0; i--) {
                stack.add(root.children.get(i));
            }
        }

        return list;
    }

    // Solution 2: Iterative
    public List<Integer> solution2Result = new ArrayList<>();

    public List<Integer> solution2(Node root) {
        if (root == null) {
            return solution2Result;
        }

        solution2Result.add(root.val);
        for (Node node : root.children) {
            preorder(node);
        }

        return solution2Result;
    }
}
