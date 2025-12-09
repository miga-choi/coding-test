#include <algorithm>
#include <vector>
using namespace std;

class ContainerWithMostWater {
public:
    /**
     * Two Pointers
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
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


    // Solution
    /**
     * Two Pointers
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            int width = right - left;
            
            int current_height = min(height[left], height[right]);
            
            int current_area = width * current_height;
            
            max_area = max(max_area, current_area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
