#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class TwoSum4InputIsABST {
public:
    void inorder(TreeNode* node, std::vector<int>& valArray) {
        if (node) {
            inorder(node->left, valArray);
            valArray.push_back(node->val);
            inorder(node->right, valArray);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        std::vector<int> valArray;

        inorder(root, valArray);

        int left = 0, right = valArray.size() - 1;
        while (left < right) {
            int sum = valArray[left] + valArray[right];
            if (sum < k) {
                left++;
            } else if (sum > k) {
                right--;
            } else {
                return true;
            }
        }

        return false;
    }

    // Solution: Using Set
    bool dfs(TreeNode* root, std::unordered_set<int>& set, int k) {
        if (root == NULL) {
            return false;
        }
        if (set.count(k - root->val)) {
            return true;
        }
        set.insert(root->val);
        return dfs(root->left, set, k) || dfs(root->right, set, k);
    }

    bool solution(TreeNode* root, int k) {
        std::unordered_set<int> set;
        return dfs(root, set, k);
    }
};
