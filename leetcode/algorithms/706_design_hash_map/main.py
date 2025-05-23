from typing import List


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)


class MyHashMap:
    nums: List[int]

    def __init__(self):
        self.nums = [(1e6 + 1) * -1]

    def put(self, key: int, value: int) -> None:
        self.nums[key] = value

    def get(self, key: int) -> int:
        return self.nums[key]

    def remove(self, key: int) -> None:
        self.nums[key] = -1


# Solution
# Solution 1: Array
class Solution1_MyHashMap:
    def __init__(self):
        self.data = [None] * 1000001

    def put(self, key: int, val: int) -> None:
        self.data[key] = val

    def get(self, key: int) -> int:
        val = self.data[key]
        return val if val != None else -1

    def remove(self, key: int) -> None:
        self.data[key] = None

# Solution 2: Array
class ListNode:
    def __init__(self, key, val, nxt):
        self.key = key
        self.val = val
        self.next = nxt


class Solution2_MyHashMap:
    def __init__(self):
        self.size = 19997
        self.mult = 12582917
        self.data = [None for _ in range(self.size)]

    def hash(self, key):
        return key * self.mult % self.size

    def put(self, key, val):
        self.remove(key)
        h = self.hash(key)
        node = ListNode(key, val, self.data[h])
        self.data[h] = node

    def get(self, key):
        h = self.hash(key)
        node = self.data[h]

        while node:
            if node.key == key:
                return node.val
            node = node.next

        return -1

    def remove(self, key: int):
        h = self.hash(key)
        node = self.data[h]

        if not node:
            return

        if node.key == key:
            self.data[h] = node.next
            return

        while node.next:
            if node.next.key == key:
                node.next = node.next.next
                return
            node = node.next
