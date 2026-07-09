/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param2 = obj.pop();
 * int param3 = obj.peek();
 * bool param4 = obj.empty();
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
  late final List<int> input;
  late final List<int> output;

  MyQueue() {
    input = List<int>.empty(growable: true);
    output = List<int>.empty(growable: true);
  }

  // Pushes element `x` to the back of the queue.
  void push(int x) {
    input.add(x);
  }

  // Removes the element from the front of the queue and returns it.
  int pop() {
    peek();
    return output.removeLast();
  }

  // Returns the element at the front of the queue.
  int peek() {
    if (output.isEmpty) {
      while (input.isNotEmpty) {
        output.add(input.removeLast());
      }
    }

    return output.last;
  }

  // Returns `true` if the queue is empty, `false` otherwise.
  bool empty() {
    return input.isEmpty && output.isEmpty;
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
  final List<int> _instack = [];
  final List<int> _outstack = [];

  Solution();

  void push(int x) {
    _instack.add(x);
  }

  int pop() {
    _moveIfNeeded();
    return _outstack.removeLast();
  }

  int peek() {
    _moveIfNeeded();
    return _outstack.last;
  }

  bool empty() {
    return _instack.isEmpty && _outstack.isEmpty;
  }

  void _moveIfNeeded() {
    if (_outstack.isEmpty) {
      while (_instack.isNotEmpty) {
        _outstack.add(_instack.removeLast());
      }
    }
  }
}
