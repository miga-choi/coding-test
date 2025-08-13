from typing import List


class ContainerWithMostWater:
    # Two Pointers
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    def maxArea(self, height: List[int]) -> int:
        left: int = 0
        right: int = len(height) - 1
        maxStored: int = 0

        while left < right:
            leftHeight: int = height[left]
            rightHeight: int = height[right]
            h: int = min(leftHeight, rightHeight)
            store: int = (right - left) * h

            maxStore = max(maxStore, store)

            if leftHeight < rightHeight:
                left += 1
            else:
                right -= 1

        return maxStore
