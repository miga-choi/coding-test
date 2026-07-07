#include <stack>
using namespace std;

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
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
class MyQueue {
    stack<int> input, output;

public:
    MyQueue() {}

    // Pushes element x to the back of the queue.
    void push(int x) {
        input.push(x);
    }

    // Removes the element from the front of the queue and returns it.
    int pop() {
        int front = peek();
        output.pop();
        return front;
    }

    // Returns the element at the front of the queue.
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    // Returns true if the queue is empty, false otherwise.
    bool empty() {
        return input.empty() && output.empty();
    }
};


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
private:
    std::stack<int> input;
    std::stack<int> output;

    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    Solution() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        transfer();
        int topElement = output.top();
        output.pop();
        return topElement;
    }
    
    int peek() {
        transfer();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
