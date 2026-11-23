#include <algorithm>     // std::max
#include <optional>      // std::optional
#include <unordered_map> // std::unordered_map
#include <vector>        // std::vector
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
    /**
     * In-order Traversal to Array + Two-Pass Run Counting
     *
     * Complexities:
     *   n - The Number of Nodes in `root`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(n)
     */
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
    /**
     * Solution 1
     * 
     * Tree Traversal + Hash Map
     *
     * Complexities:
     *   n - The Number of Nodes in `root`
     *   h - The Height of `root` 
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(h)
     */
    void count(TreeNode* node, unordered_map<int, int>& cnt) {
        if (!node) {
            return;
        }

        ++cnt[node->val];
        count(node->left, cnt);
        count(node->right, cnt);
    }

    vector<int> solution1(TreeNode* root) {
        unordered_map<int, int> cnt;
        count(root, cnt);

        int maxCnt = 0;
        for (const auto &[val, c] : cnt) {
            maxCnt = max(maxCnt, c);
        }

        vector<int> res;
        for (const auto& [val, c] : cnt) {
            if (c == maxCnt) {
                res.push_back(val);
            }
        }

        return res;
    }

    /**
     * Solution 2
     * 
     * In-order Traversal + Running Count 
     *
     * Complexities:
     *   n - The Number of Nodes in `root`
     *   h - The Height of `root` 
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(h)
     */
    optional<int> prev2;
    int cur2 = 0, maxCnt2 = 0;
    vector<int> res2;

    void visit(int v) {
        cur2 = (prev2 == v) ? cur2 + 1 : 1;
        prev2 = v;

        if (cur2 > maxCnt2) {
            maxCnt2 = cur2;
            res2.clear();
        }

        if (cur2 == maxCnt2) {
            res2.push_back(v);
        }
    }

    void inorder(TreeNode* node) {
        if (!node) {
            return;
        }

        inorder(node->left);
        visit(node->val);
        inorder(node->right);
    }

    vector<int> solution2(TreeNode* root) {
        prev2.reset();
        cur2 = maxCnt2 = 0;
        res2.clear();

        inorder(root);

        return res2;
    }

    /**
     * Solution 3
     * 
     * Morris In-order Traversal + Running Count
     *
     * Complexities:
     *   n - The Number of Nodes in `root`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    optional<int> prev3;
    int cur3 = 0, maxCnt3 = 0;
    vector<int> res3;

    void visit3(int v) {
        cur3 = (prev3 == v) ? cur3 + 1 : 1;
        prev3 = v;

        if (cur3 > maxCnt3) {
            maxCnt3 = cur3;
            res3.clear();
        }

        if (cur3 == maxCnt3) {
            res3.push_back(v);
        }
    }

    vector<int> solution3(TreeNode* root) {
        prev3.reset();
        cur3 = maxCnt3 = 0;
        res3.clear();

        TreeNode* node = root;
        while (node) {
            if (!node->left) {
                visit(node->val);
                node = node->right;
                continue;
            }

            TreeNode* pre = node->left;
            while (pre->right && pre->right != node) {
                pre = pre->right;
            }

            if (!pre->right) {
                pre->right = node;
                node = node->left;
            } else {
                pre->right = nullptr;
                visit(node->val);
                node = node->right;
            }
        }

        return res3;
    }
};
