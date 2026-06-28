import 'dart:collection';

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = MyStack();
 * obj.push(x);
 * int param2 = obj.pop();
 * int param3 = obj.top();
 * bool param4 = obj.empty();
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
  late final Queue<int> queue1;
  late final Queue<int> queue2;

  MyStack() {
    queue1 = Queue<int>();
    queue2 = Queue<int>();
  }

  // Pushes element x to the top of the stack.
  void push(int x) {
    while (queue1.isNotEmpty) {
      queue2.add(queue1.removeFirst());
    }
    queue1.add(x);
    while (queue2.isNotEmpty) {
      queue1.add(queue2.removeFirst());
    }
  }

  // Removes the element on the top of the stack and returns it.
  int pop() {
    return queue1.removeFirst();
  }

  // Returns the element on the top of the stack.
  int top() {
    return queue1.first;
  }

  // Returns `true` if the stack is empty, `false` otherwise.
  bool empty() {
    return queue1.isEmpty;
  }
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
  final Queue<int> _queue = Queue<int>();

  Solution();

  void push(int x) {
    int size = _queue.length;

    _queue.add(x);

    for (int i = 0; i < size; i++) {
      _queue.add(_queue.removeFirst());
    }
  }

  int pop() {
    return _queue.removeFirst();
  }

  int top() {
    return _queue.first;
  }

  bool empty() {
    return _queue.isEmpty;
  }
}
