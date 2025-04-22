#include <vector>
using namespace std;

class ConvertSortedArrayToBinarySearchTree {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }

        return convertToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* convertToBST(vector<int> nums, int left, int right) {
        if (right < left) {
            return nullptr;
        }

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = convertToBST(nums, left, mid - 1);
        node->right = convertToBST(nums, mid + 1, right);

        return node;
    }


    // Solution
    // Solution 1: Recursion
    TreeNode* solution1(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }

        int middle = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[middle]);

        vector<int> leftInts(nums.begin(), nums.begin() + middle);
        vector<int> rightInts(nums.begin() + middle + 1, nums.end());

        root->left = solution1(leftInts);
        root->right = solution1(rightInts);

        return root;
    }

    // Solution 2: Recursion
    TreeNode* solution2(vector<int>& nums, int start, int end) {
        if (end <= start) {
            return NULL;
        }
        int midIdx = (end + start) / 2;
        TreeNode* root = new TreeNode(nums[midIdx]);
        root->left = solution2(nums, start, midIdx);
        root->right = solution2(nums, midIdx + 1, end);
        return root;
    }

    TreeNode* solution2(vector<int>& nums) {
        return solution2(nums, 0, nums.size());
    }
};
