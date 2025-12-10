from typing import List


class ContainerWithMostWater:
    """
    # Two Pointers
    # 
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def maxArea(self, height: List[int]) -> int:
        left: int = 0
        right: int = len(height) - 1
        maxStore: int = 0

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


    # Solution
    """
    # Two Pointers
    # 
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0
        
        while left < right:
            width = right - left
            
            current_area = min(height[left], height[right]) * width
            
            max_area = max(max_area, current_area)
            
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return max_area
