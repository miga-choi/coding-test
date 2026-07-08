import java.util.Stack;

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */

/**
 * Complexities:
 *   - Time Complexity:
 *     push(x): O(1)
 *     pop(): O(1)
 *     peek(): O(1)
 *     empty(): O(1)
 *   - Space Complexity: O(N)
 */
class ImplementQueueUsingStacks {
    private Stack<Integer> inputStack;
    private Stack<Integer> outputStack;
    private int front;

    public ImplementQueueUsingStacks() {
        inputStack = new Stack<>();
        outputStack = new Stack<>();
        front = 0;
    }

    public void push(int x) {
        if (inputStack.size() == 0) {
            front = x;
        }
        inputStack.add(x);
    }

    public int pop() {
        if (outputStack.size() == 0) {
            while (inputStack.size() > 0) {
                outputStack.add(inputStack.pop());
            }
        }
        return outputStack.pop();
    }

    public int peek() {
        if (outputStack.size() == 0) {
            return front;
        }
        return outputStack.peek();
    }

    public boolean empty() {
        return inputStack.size() == 0 && outputStack.size() == 0;
    }
}


// Solution
/**
 * Complexities:
 *   - Time Complexity:
 *     push(x): O(1)
 *     pop(): O(1)
 *     peek(): O(1)
 *     empty(): O(1)
 *   - Space Complexity: O(N)
 */
class Solution {
    private Stack<Integer> inStack;
    private Stack<Integer> outStack;

    public Solution() {
        inStack = new Stack<>();
        outStack = new Stack<>();
    }

    public void push(int x) {
        inStack.push(x);
    }

    public int pop() {
        shiftStacks();
        return outStack.pop();
    }

    public int peek() {
        shiftStacks();
        return outStack.peek();
    }

    public boolean empty() {
        return inStack.isEmpty() && outStack.isEmpty();
    }

    private void shiftStacks() {
        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }
    }
}
