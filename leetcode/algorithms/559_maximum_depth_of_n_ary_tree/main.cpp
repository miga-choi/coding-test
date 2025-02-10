#include <algorithm>
#include <queue>
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

class MaximumDepthOfNAryTree {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int max = 0;

        for (Node* node : root->children) {
            int depth = maxDepth(node);
            if (depth > max) {
                max = depth;
            }
        }

        return max + 1;
    }

    // Solution 1: Recursive DFS
    int solution1(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        for (auto child : root->children) {
            depth = max(depth, solution1(child));
        }
        return 1 + depth;
    }

    // Solution 2: BFS
    int solution2(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth += 1;
            int breadth = q.size();
            for (int _ = 0; _ < breadth; ++_) {
                auto node = q.front();
                q.pop();
                for (auto child : node->children) {
                    if (child) {
                        q.push(child);
                    }
                }
            }
        }
        return depth;
    }
};
