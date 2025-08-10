#include <algorithm>
#include <vector>
using namespace std;

class ContainerWithMostWater {
public:
    /**
     * Two Pointers
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxStored = 0;

        while (left < right) {
            int leftHeight = height[left];
            int rightHeight = height[right];
            int h = min(leftHeight, rightHeight);
            int store = (right - left) * h;
            maxStored = max(maxStored, store);

            if (leftHeight < rightHeight) {
                left++;
            } else {
                right--;
            }
        }

        return maxStored;
    }
};
