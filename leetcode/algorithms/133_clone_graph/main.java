
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
     * Recursion: DFS + Hash table
     * - Time Complexity: O(V + E)
     * - Space Complexity: O(V)
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
     * Recursion: DFS + Hash table
     * - Time Complexity: O(V + E)
     * - Space Complexity: O(V)
     */
    private Map<Node, Node> visitedMap = new HashMap<>();

    public Node solution1(Node node) {
        if (node == null) {
            return null;
        }

        if (visitedMap.containsKey(node)) {
            return visitedMap.get(node);
        }

        Node clonedNode = new Node(node.val);

        visitedMap.put(node, clonedNode);

        for (Node neighbor : node.neighbors) {
            clonedNode.neighbors.add(solution1(neighbor));
        }

        return clonedNode;
    }

    /**
     * Solution 2
     *
     * Iteration: BFS + Hash table + Queue
     * - Time Complexity: O(V + E)
     * - Space Complexity: O(V)
     */
    public Node solution2(Node node) {
        if (node == null) {
            return null;
        }

        Map<Node, Node> _visitedMap = new HashMap<>();
        Queue<Node> queue = new LinkedList<>();

        Node clonedNode = new Node(node.val);

        _visitedMap.put(node, clonedNode);

        queue.add(node);

        while (!queue.isEmpty()) {
            Node currentOriginal = queue.poll();
            Node currentCloned = _visitedMap.get(currentOriginal);

            for (Node originalNeighbor : currentOriginal.neighbors) {
                if (!_visitedMap.containsKey(originalNeighbor)) {
                    Node clonedNeighbor = new Node(originalNeighbor.val);

                    _visitedMap.put(originalNeighbor, clonedNeighbor);
                    queue.add(originalNeighbor);
                }

                currentCloned.neighbors.add(_visitedMap.get(originalNeighbor));
            }
        }

        return clonedNode;
    }
}
