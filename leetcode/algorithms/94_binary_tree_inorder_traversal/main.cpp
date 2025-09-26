#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTreeInorderTraversal {
public:
    /**
     * Recursion
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    void getVal(TreeNode* node, vector<int>& array) {
        if (node != nullptr) {
            getVal(node->left, array);
            array.push_back(node->val);
            getVal(node->right, array);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> array;

        getVal(root, array);

        return array;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Recursion
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    void inorder_recursive(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        inorder_recursive(node->left, result);

        result.push_back(node->val);

        inorder_recursive(node->right, result);
    }

    vector<int> solution1(TreeNode* root) {
        vector<int> result;

        inorder_recursive(root, result);

        return result;
    }

    /**
     * Solution 2
     * 
     * Iteration
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    vector<int> solution2(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            result.push_back(current->val);

            current = current->right;
        }
        
        return result;
    }

    /**
     * Solution 3
     * 
     * Morris Traversal
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    vector<int> solution3(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* predecessor = nullptr;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                predecessor = curr->left;

                while (predecessor->right != nullptr && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    predecessor->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};
