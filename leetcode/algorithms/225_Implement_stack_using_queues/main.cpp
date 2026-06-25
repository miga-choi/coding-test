#include <queue>
using namespace std;

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
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
public:
    queue<int> myQueue;

    MyStack() {}

    // Pushes element x to the top of the stack.
    void push(int x) {
        myQueue.push(x);
        for (int i = 0; i < myQueue.size() - 1; i++) {
            int firstElement = myQueue.front();
            myQueue.push(firstElement);
            myQueue.pop();
        }
    }

    // Removes the element on the top of the stack and returns it.
    int pop() {
        int firstElement = myQueue.front();
        myQueue.pop();
        return firstElement;
    }

    // Returns the element on the top of the stack.
    int top() {
        return myQueue.front();
    }

    // Returns `true` if the stack is empty, `false` otherwise.
    bool empty() {
        return myQueue.empty();
    }
};


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
public:
    std::queue<int> q;

    Solution() {}

    void push(int x) {
        int sz = q.size();
        
        q.push(x);
        
        for (int i = 0; i < sz; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
