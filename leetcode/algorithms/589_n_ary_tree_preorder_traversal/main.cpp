#include <stack>
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

class NAryTreePreorderTraversal {
public:
    void preorder(Node* node, vector<int>& valArray) {
        if (node != nullptr) {
            valArray.push_back(node->val);
            for (Node* child : node->children) {
                preorder(child, valArray);
            }
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> valArray;
        preorder(root, valArray);
        return valArray;
    }

    // Solution 1: Iterative
    void travel(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        result.push_back(root->val);
        for (Node* child : root->children) {
            travel(child, result);
        }
    }

    vector<int> solution1(Node* root) {
        vector<int> result;
        travel(root, result);
        return result;
    }

    // Solution 2: Recursive
    vector<int> solution2(Node* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* cur = stk.top();
            stk.pop();
            result.push_back(cur->val);
            for (int i = cur->children.size() - 1; i >= 0; i--) {
                if (cur->children[i] != nullptr) {
                    stk.push(cur->children[i]);
                }
            }
        }

        return result;
    }
};
