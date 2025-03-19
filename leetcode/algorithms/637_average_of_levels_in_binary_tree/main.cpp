#include <queue>
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

class AverageOfLevelsInBinaryTree {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<TreeNode*> queue(10000);
        int left = 0, right = 0;

        queue[right++] = root;
        while (left < right) {
            int nodeCount = right - left;
            double sum = 0;
            for (int i = 0; i < nodeCount; i++) {
                TreeNode* node = queue[left++];
                sum += node->val;
                if (node->left) {
                    queue[right++] = node->left;
                }
                if (node->right) {
                    queue[right++] = node->right;
                }
            }
            result.push_back(sum / nodeCount);
        }

        return result;
    }

    // Solution
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long temp = 0;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
                temp += t->val;
            }
            res.push_back((double)temp / s);
        }
        return res;
    }
};
