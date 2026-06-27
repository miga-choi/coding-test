import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */

/**
 * Complexities:
 *   - Time Complexity:
 *     push: O(N)
 *     pop: O(1)
 *     top: O(1)
 *     empty: O(1)
 *   - Space Complexity: O(N)
 */
class MyStack {
    Stack<Integer> inputStack;
    Stack<Integer> outputStack;

    public MyStack() {
        inputStack = new Stack<>();
        outputStack = new Stack<>();
    }

    public void push(int x) {
        if (!inputStack.isEmpty()) {
            outputStack.push(inputStack.pop());
        }
        inputStack.push(x);
    }

    public int pop() {
        if (!inputStack.isEmpty()) {
            return inputStack.pop();
        }
        return outputStack.pop();
    }

    public int top() {
        if (!inputStack.isEmpty()) {
            return inputStack.firstElement();
        }
        return outputStack.lastElement();
    }

    public boolean empty() {
        return !(!inputStack.isEmpty() || !outputStack.isEmpty());
    }


    // Solution
    /**
     * Complexities:
     *   - Time Complexity:
     *     push: O(N)
     *     pop: O(1)
     *     top: O(1)
     *     empty: O(1)
     *   - Space Complexity: O(N)
     */
    class Solution {
        private Queue<Integer> queue;

        public Solution() {
            // Java의 Queue 인터페이스 구현체로 LinkedList 사용
            queue = new LinkedList<>();
        }

        // 1. 스택에 원소 삽입 (LIFO 구조를 만들기 위해 회전 연산 수행)
        // 시간 복잡도: O(N)
        public void push(int x) {
            int size = queue.size();
            // 일단 큐의 맨 뒤에 원소를 넣음
            queue.offer(x);

            // 새로 들어온 원소(x)가 맨 앞으로 오도록
            // 기존에 있던 원소들을 꺼내서 다시 뒤로 넣음 (큐 회전)
            for (int i = 0; i < size; i++) {
                queue.offer(queue.poll());
            }
        }

        // 2. 스택의 최상단 원소 제거 및 반환
        // 시간 복잡도: O(1)
        public int pop() {
            return queue.poll();
        }

        // 3. 스택의 최상단 원소 조회 (제거하지 않음)
        // 시간 복잡도: O(1)
        public int top() {
            return queue.peek();
        }

        // 4. 스택이 비어있는지 확인
        // 시간 복잡도: O(1)
        public boolean empty() {
            return queue.isEmpty();
        }
    }
}
