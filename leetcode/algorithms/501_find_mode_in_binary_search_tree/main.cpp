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

class FindModeInBinarySearchTree {
public:
    void order(TreeNode* root, vector<int>& numArray) {
        if (!root) {
            return;
        }
        order(root->left, numArray);
        numArray.push_back(root->val);
        order(root->right, numArray);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> numArray;
        order(root, numArray);

        int currentCount = 0;
        int currentNum = numArray[0];
        int maxCount = 0;

        for (int i = 0; i < numArray.size(); i++) {
            if (numArray[i] == currentNum) {
                currentCount++;
            } else {
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                }
                currentCount = 1;
                currentNum = numArray[i];
            }
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
        }

        currentCount = 0;
        currentNum = numArray[0];

        vector<int> result;

        for (int i = 0; i < numArray.size(); i++) {
            if (numArray[i] == currentNum) {
                currentCount++;
            } else {
                if (currentCount == maxCount) {
                    result.push_back(currentNum);
                }
                currentCount = 1;
                currentNum = numArray[i];
            }
        }

        if (currentCount == maxCount) {
            result.push_back(currentNum);
        }

        return result;
    }

    // Solution
    int maxFreq = 0, currFreq = 0, precursor = INT_MIN;

    vector<int> res;

    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            // Stop condition
            return;
        }

        // Traverse left subtree
        inorderTraversal(root->left);

        if (precursor == root->val) {
            currFreq++;
        } else {
            currFreq = 1;
        }

        if (currFreq > maxFreq) {
            // Current node value has higher frequency than any previous visited
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        } else if (currFreq == maxFreq) {
            // Current node value has a frequency equal to the highest of previous visited
            res.push_back(root->val);
        }

        // Update the precursor
        precursor = root->val;

        // Traverse right subtree
        inorderTraversal(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorderTraversal(root);
        return res;
    }
};
