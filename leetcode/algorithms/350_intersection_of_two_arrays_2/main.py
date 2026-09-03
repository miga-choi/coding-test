from collections import Counter, defaultdict
from typing import List


class IntersectionOfTwoArraysII:
    """
    # Complexities:
    #   N - The size of `nums1`
    #   M - The size of `nums2`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(N + M)
    """
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        numsMap: dict = {}

        for num1 in nums1:
            if numsMap.get(num1) == None:
                numsMap.update({num1: 1})
            else:
                numsMap.update({num1: numsMap.get(num1) + 1})

        for num2 in nums2:
            if numsMap.get(num2) != None and numsMap.get(num2) > 0:
                result.append(num2)
                numsMap.update({num2: numsMap.get(num2) - 1})

        return result


    # Solution
    """
    # Solution 1
    #
    # collections.Counter
    #
    # Complexities:
    #   N - The size of `nums1`
    #   M - The size of `nums2`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(N + M)
    """
    def solution1(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list((Counter(nums1) & Counter(nums2)).elements())

    """
    # Solution 2
    #
    # collections.defaultdict
    #
    # Complexities:
    #   N - The size of `nums1`
    #   M - The size of `nums2`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(min(N, M))
    """
    def solution2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        count = defaultdict(int)
        for x in nums1:
            count[x] += 1

        result = []
        for x in nums2:
            if count[x] > 0:
                result.append(x)
                count[x] -= 1

        return result

    """
    # Solution 3
    #
    # Sorting + Two Pointers
    #
    # Complexities:
    #   N - The size of `nums1`
    #   M - The size of `nums2`
    #   - Time Complexity: O(N * logᴺ + M * logᴹ)
    #   - Space Complexity: O(min(N, M))
    """
    def solution3(self, nums1: List[int], nums2: List[int]) -> List[int]:
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
                result.append(nums1[i])
                i += 1
                j += 1

        return result
