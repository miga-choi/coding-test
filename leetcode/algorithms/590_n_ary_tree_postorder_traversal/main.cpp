#include <functional>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void postorder(Node* node, vector<int>& valArray) {
        if (node != nullptr) {
            for (Node* child : node->children) {
                postorder(child, valArray);
            }
            valArray.push_back(node->val);
        }
    }

    vector<int> postorder(Node* root) {
        vector<int> valArray;
        postorder(root, valArray);
        return valArray;
    }

    // Solution: DFS
    vector<int> solution(Node* root) {
        // If the root is null, return an empty vector
        if (!root) {
            return {};
        }

        vector<int> res;

        // Define the DFS function
        function<void(Node*)> dfs = [&](Node* node) {
            // Recursively call dfs for each child of the current node
            for (Node* child : node->children) {
                dfs(child);
            }
            // Append the value of the current node to the result vector
            res.push_back(node->val);
        };

        // Start DFS from the root
        dfs(root);

        // Return the result vector containing node values in post-order
        return res;
    }
};
