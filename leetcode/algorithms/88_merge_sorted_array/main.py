from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(-1, -1 - n, -1):
            nums1[i] = nums2[i]
        nums1[0:] = sorted(nums1)


    # Best Solution
    def merge_two_sorted_arrays(A: List[int], m: int, B: List[int], n: int) -> None:
        a, b, write_index = m - 1, n - 1, m + n - 1

        while b >= 0:
            if a >= 0 and A[a] > B[b]:
                A[write_index] = A[a]
                a -= 1
            else:
                A[write_index] = B[b]
                b -= 1

            write_index -= 1
