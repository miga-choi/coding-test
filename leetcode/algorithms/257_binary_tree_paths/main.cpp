#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTreePaths {
public:
    void calculatePath(TreeNode* root, vector<string> &stringArray, string charArray) {
        if (!root) {
            return;
        }

        charArray = charArray + (charArray.size() == 0 ? "" : "->") + to_string(root->val);

        if (!root->left && !root->right) {
            stringArray.push_back(charArray);
        } else {
            calculatePath(root->left, stringArray, charArray);
            calculatePath(root->right, stringArray, charArray);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> stringArray;
        calculatePath(root, stringArray, "");
        return stringArray;
    }


    // Solution
    void binaryTreePaths(vector<string> &result, TreeNode* root, string t) {
        if (!root->left && !root->right) {
            result.push_back(t);
            return;
        }

        if (root->left) {
            binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
        }
        if (root->right) {
            binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
        }
    }

    vector<string> solution(TreeNode* root) {
        vector<string> result;
        if (!root) {
            return result;
        }

        binaryTreePaths(result, root, to_string(root->val));
        return result;
    }
};
