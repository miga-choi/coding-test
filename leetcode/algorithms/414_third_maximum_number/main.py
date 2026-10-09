from typing import List
import heapq


class ThirdMaximumNumber:
    """
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def thirdMax(self, nums: List[int]) -> int:
        nums = list(set(nums))

        if len(nums) > 2:
            for _ in range(2):
                nums = list(filter(lambda x: x < max(nums), nums))

        return max(nums)


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, nums: List[int]) -> int:
        distinct = sorted(set(nums), reverse=True)
        return distinct[2] if len(distinct) >= 3 else distinct[0]

    """
    # Solution 2
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums: List[int]) -> int:
        first = second = third = None

        for x in nums:
            if x in (first, second, third):
                continue

            if first is None or x > first:
                first, second, third = x, first, second
            elif second is None or x > second:
                second, third = x, second
            elif third is None or x > third:
                third = x

        return third if third is not None else first

    """
    # Solution 3
    #
    # Heap of Size 3
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, nums: List[int]) -> int:
        heap = []
        seen = set()

        for x in nums:
            if x in seen:
                continue
            seen.add(x)
            heapq.heappush(heap, x)
            if len(heap) > 3:
                heapq.heappop(heap)

        return heap[0] if len(heap) == 3 else max(heap)
