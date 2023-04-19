class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums[:] = sorted(filter(lambda num: num != val, nums))
        return len(nums)
