import heapq
from queue import PriorityQueue
from typing import List

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)


class KthLargest:
    priorityQueue: PriorityQueue
    k: int

    def __init__(self, k: int, nums: List[int]):
        self.priorityQueue = PriorityQueue(k)
        self.k = k
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        if self.priorityQueue.qsize() < self.k:
            self.priorityQueue.put(val)
        else:
            top: int = self.priorityQueue.get(0)
            if top < val:
                self.priorityQueue.put(val)
            else:
                self.priorityQueue.put(top)

        top: int = self.priorityQueue.get(0)
        self.priorityQueue.put(top)

        return top


# Solution
class Solution_KthLargest(object):
    def __init__(self, k, nums):
        self.pool = nums
        self.k = k
        heapq.heapify(self.pool)
        while len(self.pool) > k:
            heapq.heappop(self.pool)

    def add(self, val):
        if len(self.pool) < self.k:
            heapq.heappush(self.pool, val)
        elif val > self.pool[0]:
            heapq.heapreplace(self.pool, val)
        return self.pool[0]
