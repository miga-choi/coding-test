from typing import List


class IntersectionOfTwoArraysII:
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
    def solution(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # Sort both the arrays first...
        sortedArr1 = sorted(nums1)
        sortedArr2 = sorted(nums2)

        # Use two pointers i and j for the two arrays and initialize both with zero.
        i = 0
        j = 0

        # Create a output list to store the output...
        output = []
        while i < len(sortedArr1) and j < len(sortedArr2):
            # If sortedArr1[i] is less than sortedArr2[j]...
            # Leave the smaller element and go to next(greater) element in nums1...
            if sortedArr1[i] < sortedArr2[j]:
                i += 1

            # If sortedArr1[i] is greater than sortedArr2[j]...
            # Go to next(greater) element in nums2 array...
            elif sortedArr2[j] < sortedArr1[i]:
                j += 1

            # If both the elements intersected...
            # Add this element to output & increment both i and j.
            else:
                output.append(sortedArr1[i])
                i += 1
                j += 1

        # Return the output array...
        return output
