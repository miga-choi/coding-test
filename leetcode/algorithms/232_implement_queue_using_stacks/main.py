# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()

"""
# Complexities:
#   - Time Complexity:
#     push(x): O(1)
#     pop(): O(1)
#     peek(): O(1)
#     empty(): O(1)
#   - Space Complexity: O(N)
"""
class MyQueue:
    def __init__(self):
        self.inputStack = []
        self.outputStack = []

    def push(self, x: int) -> None:
        self.inputStack.append(x)

    def pop(self) -> int:
        if len(self.outputStack) == 0:
            while len(self.inputStack) > 0:
                self.outputStack.append(self.inputStack.pop())
        return self.outputStack.pop()

    def peek(self) -> int:
        if len(self.outputStack) > 0:
            return self.outputStack[len(self.outputStack) - 1]
        return self.inputStack[0]

    def empty(self) -> bool:
        return len(self.inputStack) == 0 and len(self.outputStack) == 0


# Solution
"""
# Complexities:
#   - Time Complexity:
#     push(x): O(1)
#     pop(): O(1)
#     peek(): O(1)
#     empty(): O(1)
#   - Space Complexity: O(N)
"""
class Solution:
    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    def push(self, x: int) -> None:
        self.in_stack.append(x)

    def pop(self) -> int:
        self._move()
        return self.out_stack.pop()

    def peek(self) -> int:
        self._move()
        return self.out_stack[-1]

    def empty(self) -> bool:
        return not self.in_stack and not self.out_stack

    def _move(self) -> None:
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
