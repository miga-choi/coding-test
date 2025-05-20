from typing import List


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)


class MyHashSet:
    nums: List[int]

    def __init__(self):
        self.nums = 1000001 * [0]

    def add(self, key: int) -> None:
        self.nums[key] = 1

    def remove(self, key: int) -> None:
        self.nums[key] = 0

    def contains(self, key: int) -> bool:
        return self.nums[key] == 1


# Solution
class Solution_MyHashSet:
    def eval_hash(self, key):
        return ((key*1031237) & (1 << 20) - 1) >> 5

    def __init__(self):
        self.arr = [[] for _ in range(1 << 15)]

    def add(self, key: int) -> None:
        t = self.eval_hash(key)
        if key not in self.arr[t]:
            self.arr[t].append(key)

    def remove(self, key: int) -> None:
        t = self.eval_hash(key)
        if key in self.arr[t]:
            self.arr[t].remove(key)

    def contains(self, key: int) -> bool:
        t = self.eval_hash(key)
        return key in self.arr[t]
