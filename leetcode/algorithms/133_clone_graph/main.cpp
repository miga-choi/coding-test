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
     * Recursion: DFS + Hash table
     * - Time Complexity: O(V + E)
     * - Space Complexity: O(V)
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
     * Solution 1
     * 
     * Recursion: DFS + Hash table
     * - Time Complexity: O(V + E)
     * - Space Complexity: O(V)
     */
    unordered_map<Node*, Node*> visited_map;

    Node* solution1(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (visited_map.count(node)) {
            return visited_map[node];
        }

        Node* cloned_node = new Node(node->val);

        visited_map[node] = cloned_node;

        for (Node* neighbor : node->neighbors) {
            cloned_node->neighbors.push_back(solution1(neighbor));
        }

        return cloned_node;
    }

    /**
     * Solution 2
     * 
     * Iteration: BFS + Hash table + Queue
     * - Time Complexity: O(V + E)
     * - Space Complexity: O(V)
     */
    Node* solution2(Node* node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<Node*, Node*> visited_map;
        queue<Node*> q;

        Node* cloned_head = new Node(node->val);
        visited_map[node] = cloned_head;
        q.push(node);

        while (!q.empty()) {
            Node* current_original = q.front();
            q.pop();

            for (Node* neighbor_original : current_original->neighbors) {
                if (visited_map.find(neighbor_original) == visited_map.end()) {
                    Node* neighbor_cloned = new Node(neighbor_original->val);
                    visited_map[neighbor_original] = neighbor_cloned;
                    q.push(neighbor_original);
                }

                visited_map[current_original]->neighbors.push_back(
                    visited_map[neighbor_original]);
            }
        }

        return cloned_head;
    }
};
