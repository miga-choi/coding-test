#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * Two Pointers
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
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
