from collections import deque


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

"""
# Complexities:
#   - Time Complexity:
#     push: O(N)
#     pop: O(1)
#     top: O(1)
#     empty: O(1)
#   - Space Complexity: O(N)
"""
class MyStack:
    def __init__(self):
        self.inputStack = []
        self.outputStack = []

    def push(self, x: int) -> None:
        if len(self.inputStack) > 0:
            self.outputStack.append(self.inputStack.pop())
        self.inputStack.append(x)

    def pop(self) -> int:
        if len(self.inputStack) > 0:
            return self.inputStack.pop()
        else:
            return self.outputStack.pop()

    def top(self) -> int:
        if len(self.inputStack) > 0:
            return self.inputStack[0]
        else:
            return self.outputStack[len(self.inputStack) - 1]

    def empty(self) -> bool:
        if len(self.inputStack) > 0 or len(self.outputStack) > 0:
            return False
        return True


# Solution
"""
# Complexities:
#   - Time Complexity:
#     push: O(N)
#     pop: O(1)
#     top: O(1)
#     empty: O(1)
#   - Space Complexity: O(N)
"""
class Solution:
    def __init__(self):
        self.queue = deque()

    def push(self, x: int) -> None:
        size = len(self.queue)
        
        self.queue.append(x)
        
        for _ in range(size):
            self.queue.append(self.queue.popleft())

    def pop(self) -> int:
        return self.queue.popleft()

    def top(self) -> int:
        return self.queue[0]

    def empty(self) -> bool:
        return not self.queue
