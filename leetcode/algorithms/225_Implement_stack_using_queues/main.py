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

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()


# Best Solution
from collections import deque 

class BestSolution:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = deque()
        
    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        tmp = deque([x])
        tmp.extend(self.queue)
        self.queue = tmp
        
    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.queue.popleft()

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue) == 0