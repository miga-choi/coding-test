from typing import List


class IntersectionOfTwoArrays:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        for num1 in nums1:
            if num1 in nums2:
                result.append(num1)
        return list(set(result))


    # Solution
    def solution(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = {}
        res = []
        for n in nums1:
            d[n] = 1

        for n in nums2:
            # Check if n is in dictionary and not in the result
            if n in d and d[n]:
                res.append(n)
                # It will set the value of d[n] = 0 which will indicate we already added n in result
                d[n] -= 1

        return res
