#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTreeTilt {
public:
    int sumVal(TreeNode* node, int& total) {
        if (node == nullptr) {
            return 0;
        }

        int left = sumVal(node->left, total);
        int right = sumVal(node->right, total);

        total += abs(left - right);

        return left + right + node->val;
    }

    int findTilt(TreeNode* root) {
        int total = 0;
        sumVal(root, total);
        return total;
    }

    // Solution
    int totalTilt = 0;

    int valueSum(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftSum = valueSum(node->left);
        int rightSum = valueSum(node->right);
        int tilt = abs(leftSum - rightSum);
        totalTilt += tilt;

        // return the sum of values starting from this node.
        return node->val + leftSum + rightSum;
    }

    int solution(TreeNode* root) {
        totalTilt = 0;
        valueSum(root);
        return totalTilt;
    }
};
