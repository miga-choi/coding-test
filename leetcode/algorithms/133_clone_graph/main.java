
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class CloneGraph {
    class Node {
        public int val;
        public List<Node> neighbors;

        public Node() {
            val = 0;
            neighbors = new ArrayList<>();
        }

        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<>();
        }

        public Node(int _val, ArrayList<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    }

    /**
     * DFS
     *
     * Complexities:
     *   V - Number of Vertex in `s`
     *   E - Number of Edge in `s`
     *   - Time Complexity: O(V + E)
     *   - Space Complexity: O(V)
     */
    private Map<Node, Node> nodeMap = new HashMap<>();

    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }

        if (nodeMap.containsKey(node)) {
            return nodeMap.get(node);
        }

        Node result = new Node(node.val);

        nodeMap.put(node, result);

        for (Node neighbor : node.neighbors) {
            result.neighbors.add(cloneGraph(neighbor));
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * DFS
     *
     * Complexities:
     *   V - Number of Vertex in `s`
     *   E - Number of Edge in `s`
     *   - Time Complexity: O(V + E)
     *   - Space Complexity: O(V)
     */
    private Map<Node, Node> visitedMap = new HashMap<>();

    public Node solution1(Node node) {
        if (node == null) {
            return null;
        }

        if (visitedMap.containsKey(node)) {
            return visitedMap.get(node);
        }

        Node clonedNode = new Node(node.val, new ArrayList<>());

        visitedMap.put(node, clonedNode);

        for (Node neighbor : node.neighbors) {
            clonedNode.neighbors.add(cloneGraph(neighbor));
        }

        return clonedNode;
    }

    /**
     * Solution 2
     * 
     * BFS
     *
     * Complexities:
     *   V - Number of Vertex in `s`
     *   E - Number of Edge in `s`
     *   - Time Complexity: O(V + E)
     *   - Space Complexity: O(V)
     */
    public Node solution2(Node node) {
        if (node == null) {
            return null;
        }

        Map<Node, Node> visitedMap2 = new HashMap<>();
        Queue<Node> queue = new LinkedList<>();

        Node clonedNode = new Node(node.val, new ArrayList<>());
        visitedMap2.put(node, clonedNode);
        queue.offer(node);

        while (!queue.isEmpty()) {
            Node current = queue.poll();

            for (Node neighbor : current.neighbors) {
                if (!visitedMap2.containsKey(neighbor)) {
                    visitedMap2.put(neighbor, new Node(neighbor.val, new ArrayList<>()));
                    queue.offer(neighbor);
                }

                visitedMap2.get(current).neighbors.add(visitedMap2.get(neighbor));
            }
        }

        return clonedNode;
    }
}
