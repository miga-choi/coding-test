from typing import List


class IntersectionOfTwoArrays:
    """
    # Complexities:
    #   N - The size of `nums1`
    #   M - The size of `nums2`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(N)
    """
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []

        for num1 in nums1:
            if num1 in nums2:
                result.append(num1)

        return list(set(result))


    # Solution
    """
    # Solution 1
    #
    # set
    #
    # Complexities:
    #   N - The size of `nums1`
    #   M - The size of `nums2`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(N + M)
    """
    def solution1(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # return list(set(nums1).intersection(nums2))
        return list(set(nums1) & set(nums2))

    """
    # Solution 2
    #
    # Sort + Two pointers
    #
    # Complexities:
    #   N - The size of `nums1`
    #   M - The size of `nums2`
    #   - Time Complexity: O(N * logᴺ + M * logᴹ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        i = j = 0
        result = []

        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                i += 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                if not result or result[-1] != nums1[i]:
                    result.append(nums1[i])
                i += 1
                j += 1

        return result
