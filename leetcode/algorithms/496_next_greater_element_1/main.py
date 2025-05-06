from typing import List


class NextGreaterElementI:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []

        for i in range(len(nums1)):
            index = nums2.index(nums1[i])
            if index >= 0:
                greaters = list(filter(lambda x: x > nums1[i], nums2[index::]))
                if len(greaters) > 0:
                    result.append(greaters[0])
                else:
                    result.append(-1)
            else:
                result.append(-1)

        return result


    # Solution
    def solution(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if not nums2:
            return None

        mapping = {}
        result = []
        stack = []
        stack.append(nums2[0])

        for i in range(1, len(nums2)):
            # if stack is not empty, then compare it's last element with nums2[i]
            while stack and nums2[i] > stack[-1]:
                # if the new element is greater than stack's top element, then add this to dictionary
                mapping[stack[-1]] = nums2[i]
                # since we found a pair for the top element, remove it.
                stack.pop()

            # add the element nums2[i] to the stack because we need to find a number greater than this
            stack.append(nums2[i])

        # if there are elements in the stack for which we didn't find a greater number, map them to -1
        for element in stack:
            mapping[element] = -1

        for i in range(len(nums1)):
            result.append(mapping[nums1[i]])

        return result
