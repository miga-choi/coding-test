# Python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums[:] = sorted(list(dict.fromkeys(nums)))
        return len(nums)

    # Best Solution
    def bestSolution(self, nums):
        nums[:] = OrderedDict.fromkeys(nums)
        return len(nums)


# Python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums[:] = list(dict.fromkeys(nums))
        return len(nums)

    # Best Solution
    def bestSolution(self, nums: List[int]) -> int:
        nums[:] = sorted(set(nums))
        return len(nums)
