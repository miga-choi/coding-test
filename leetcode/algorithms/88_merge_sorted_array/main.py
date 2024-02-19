from typing import List


class MergeSortedArray:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(-1, -1 - n, -1):
            nums1[i] = nums2[i]
        nums1[0:] = sorted(nums1)


    # Best Solution
    # Best Solution 1: STL
    def bestSolution1(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        for j in range(n):
            nums1[m + j] = nums2[j]
        nums1.sort()

    # Best Solution 2: Two Pointer
    def bestSolution2(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i = m - 1
        j = n - 1
        k = m + n - 1

        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

    # Best Solution 3:
    def bestSolution3(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        while m > 0 and n > 0:
            if nums1[m - 1] >= nums2[n - 1]:
                nums1[m + n - 1] = nums1[m - 1]
                m -= 1
            else:
                nums1[m + n - 1] = nums2[n - 1]
                n -= 1
        if n > 0:
            nums1[:n] = nums2[:n]

    # Best Solution 3:
    def bestSolution3(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # Initialize nums1's index
        i = m - 1
        # Initialize nums2's index
        j = n - 1
        # Initialize a variable k to store the last index of the 1st array...
        k = m + n - 1
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                k -= 1
                i -= 1
            else:
                nums1[k] = nums2[j]
                k -= 1
                j -= 1

    # Best Solution 4:
    def bestSolution4(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        idx = 0
        for i in range(len(nums1)):
            if idx >= n:
                break
            if nums1[i] == 0:
                nums1[i] = nums2[idx]
                idx += 1
        nums1.sort()
