#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class CloneGraph {
public:
    /**
     * HashMap + DFS
     *
     * Complexities:
     *   V - Number of Vertex in `s`
     *   E - Number of Edge in `s`
     *   - Time Complexity: O(V + E)
     *   - Space Complexity: O(V)
     */
    unordered_map<Node*, Node*> node_map;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node_map.count(node) > 0) {
            return node_map[node];
        }

        Node* result = new Node(node->val);

        node_map[node] = result;

        for (Node* neighbor : node->neighbors) {
            result->neighbors.push_back(cloneGraph(neighbor));
        }

        return result;
    }


    // Solution
    /**
     * HashMap + DFS
     *
     * Complexities:
     *   V - Number of Vertex in `s`
     *   E - Number of Edge in `s`
     *   - Time Complexity: O(V + E)
     *   - Space Complexity: O(V)
     */
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* cloneNode = new Node(node->val);

        visited[node] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};
