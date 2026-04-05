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

    /**
     * Divide-and-conquer
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(logᴺ)
     */
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
    /**
     * Divide-and-conquer
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(logᴺ)
     */
    TreeNode* buildBST(const std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = buildBST(nums, left, mid - 1);
        
        node->right = buildBST(nums, mid + 1, right);

        return node;
    }

    TreeNode* solution(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        return buildBST(nums, 0, nums.size() - 1);
    }
};
