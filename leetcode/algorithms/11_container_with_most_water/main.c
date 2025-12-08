#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * Two Pointer
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxStored = 0;

    while (left < right) {
        int leftHeight = height[left];
        int rightHeight = height[right];

        int h = MIN(leftHeight, rightHeight);
        int store = (right - left) * h;

        maxStored = MAX(maxStored, store);

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
 * Two Pointer
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int h = MIN(height[left], height[right]);
        int w = right - left;
        int current_area = h * w;

        max_area = MAX(max_area, current_area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}
