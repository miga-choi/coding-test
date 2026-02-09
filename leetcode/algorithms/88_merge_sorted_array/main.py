from typing import List


class MergeSortedArray:
    """
    # Three Pointers from the End
    # 
    # Complexities:
    #   M - Size of `nums1`
    #   N - Size of `nums2`
    #   - Time Complexity: O(M + N)
    #   - Time Complexity: O(1)
    """
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1: int = m - 1
        p2: int = n - 1
        p: int = m + n - 1

        while p2 >= 0:
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
            p -= 1


    # Solution
    """
    # Three Pointers from the End
    # 
    # Complexities:
    #   M - Size of `nums1`
    #   N - Size of `nums2`
    #   - Time Complexity: O(M + N)
    #   - Time Complexity: O(1)
    """
    def solution(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = m - 1
        p2 = n - 1
        p = m + n - 1
        
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
            p -= 1
        
        nums1[:p2 + 1] = nums2[:p2 + 1]
