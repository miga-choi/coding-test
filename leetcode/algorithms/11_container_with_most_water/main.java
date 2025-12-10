class ContainerWithMostWater {
    /**
     * Two Pointers
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxStored = 0;

        while (left < right) {
            int leftHeight = height[left];
            int rightHeight = height[right];
            int h = Math.min(leftHeight, rightHeight);
            int store = (right - left) * h;

            maxStored = Math.max(maxStored, store);

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
    public int solution(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;

        while (left < right) {
            int currentHeight = Math.min(height[left], height[right]);
            int currentWidth = right - left;
            int currentArea = currentHeight * currentWidth;

            maxArea = Math.max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
}
