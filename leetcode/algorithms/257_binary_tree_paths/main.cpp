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
    /**
     * DFS + Backtracking
     *
     * Complexities:
     *   N - The number of nodes in `root`
     *   H - The height of tree in `root`
     *   - Time Complexity: O(N * H)
     *   - Space Complexity: O(H)
     */
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
    /**
     * DFS + Backtracking
     *
     * Complexities:
     *   N - The number of nodes in `root`
     *   H - The height of tree in `root`
     *   - Time Complexity: O(N * H)
     *   - Space Complexity: O(H)
     */
    void dfs(TreeNode* node, vector<int>& path, vector<string>& result) {
        if (node == nullptr) {
            return;
        }

        path.push_back(node->val);
        
        if (node->left == nullptr && node->right == nullptr) {
            string pathStr = "";
            for (size_t i = 0; i < path.size(); ++i) {
                if (i > 0) {
                    pathStr += "->";
                }
                pathStr += to_string(path[i]);
            }
            result.push_back(pathStr);
        } else {
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }

        path.pop_back();
    }

    vector<string> solution(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        
        dfs(root, path, result);
        
        return result;
    }
};
